#include "accepter.h"
#include "server.h"
#include "accepted_session_mgr.h"
#include "logger_macro.h"

Accepter::Accepter()
{
	m_pTcpSock = new TcpSocket();
}

Accepter::~Accepter()
{
	if(NULL != m_pTcpSock)
	{
		delete m_pTcpSock;
		m_pTcpSock = NULL;
	}
}

int Accepter::Init(const char* pszIP, int port)
{
	LOG_DEBUG( "ip:" << pszIP << " port:" << port);
	int ret = 0;
	if(0 == strlen(pszIP))
	{
		ret = m_pTcpSock->Listen(NULL, port);
	}
	else
	{
		ret = m_pTcpSock->Listen(pszIP, port);
	}
	
	if(ret < 0)
		return ret;
	
	return Server::Instance().GetEpoll().AddReadEvent(m_pTcpSock->GetFd(), this);
}

int Accepter::Handle(int event)
{	
	LOG_DEBUG( "Accepter::Handle" );
	Session* pSession = Server::Instance().GetIdleSessionMgr()->GetSession();
	if(NULL == pSession)
	{
		LOG_DEBUG( "get idle session failed" );
		Server::Instance().GetIdleSessionMgr()->PutSession(pSession);
		return -1;
	}
	
	if( 0 > m_pTcpSock->Accept(pSession->GetTcpSocket()))
	{
		LOG_DEBUG("Accepter::Handle: accept error" );
		Server::Instance().GetIdleSessionMgr()->PutSession(pSession);
		return -1;
	}
	
	if( !Server::Instance().GetAcceptedSessionMgr()->AddSession(pSession) )
	{
		Server::Instance().GetIdleSessionMgr()->PutSession(pSession);
		return -1;
	}
	
	return Server::Instance().GetEpoll().AddReadEvent(pSession->GetFd(), pSession);
}