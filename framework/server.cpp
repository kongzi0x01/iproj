#include "server.h"

Server::Server()
{}

Server::~Server()
{
	if(m_pAcceptedSessionMgr != NULL)
	{
		delete m_pAcceptedSessionMgr;
		m_pAcceptedSessionMgr = NULL;
	}
	if(m_pIdleSessionMgr != NULL)
	{
		delete m_pIdleSessionMgr;
		m_pIdleSessionMgr = NULL;
	}
	if(m_pConnectorMgr != NULL)
	{
		delete m_pConnectorMgr;
		m_pConnectorMgr = NULL;
	}
}

Server& Server::Instance()
{
	static Server instance;
	return instance;
}

int Server::Init(Accepter& accepter, const char* pszIP, int port)
{
	m_pAcceptedSessionMgr = new AcceptedSessionMgr();
	m_pIdleSessionMgr = new IdleSessionMgr();
	m_pConnectorMgr = new ConnectorMgr();
	
	return accepter.Init(pszIP, port);
}

int Server::Run(int timeout_ms)
{
	for(;;)
	{
		int ret = m_epoll.EpollWait(timeout_ms);
		if(ret < 0)
		{
			return -1;
		}
	}
	return 0;
}
