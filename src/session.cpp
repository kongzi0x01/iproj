#include "session.h"
#include "server.h"

#include <cerrno>
#include <unistd.h>
#include <iostream>
using namespace std;

Session::Session()
{
	m_pSendBuffer = new CircleBuffer();
	m_pRecvBuffer = new CircleBuffer();
	m_pSock = new TcpSocket();
}

Session::~Session()
{
	if(NULL != m_pSendBuffer)
	{
		delete m_pSendBuffer;
		m_pSendBuffer = NULL;
	}
	if(NULL != m_pRecvBuffer)
	{
		delete m_pRecvBuffer;
		m_pRecvBuffer = NULL;
	}
	if(NULL != m_pSock)
	{
		delete m_pSock;
		m_pSock = NULL;
	}
	if(NULL != m_pProcessor)
	{
		delete m_pProcessor;
		m_pProcessor = NULL;
	}
}

void Session::Close()
{
	if (!m_pSock->IsGood())
    {
        return;
    }
	
	Server::Instance().GetIdleSessionMgr()->PutSession(this);
	Server::Instance().GetAcceptedSessionMgr()->DelSession(this);
	Server::Instance().GetEpoll().DelEvent(GetFd());
	cout << "idle session num : " << Server::Instance().GetIdleSessionMgr()->GetTotalNum() << endl; 
	cout << "accepted session num : " << Server::Instance().GetAcceptedSessionMgr()->GetCurAcceptedNum() << endl; 
	
	m_pSendBuffer->Reset();
	m_pRecvBuffer->Reset();
	m_pSock->Close();
}

int Session::OnSockRead()
{
	int uSpace = m_pRecvBuffer->GetSpaceSize();
	int iRecv = m_pSock->Recv(m_pRecvBuffer->GetSpace(), uSpace);

	if ( iRecv > 0 )
	{
		m_pRecvBuffer->AddDataSize(iRecv);
		if ( m_pRecvBuffer->IsReachTail() )	
		{
			m_pRecvBuffer->MigrateDataToHead();	
		}
		if ( m_pProcessor->Deal(*this) < 0 )
		{
			Close();
		}
	}
	else if ( iRecv == -1 )
	{
	    cout << "Session::Read errno: " << errno << endl;
		// Blocking errors are okay, just move on
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			return iRecv;
		}

		Close();
	}
	else
		Close();
	return iRecv;
}

int Session::OnSockWrite()
{
	if ( m_pSendBuffer->GetDataSize() == 0 )
	{
		return 0;
	}
	int iSend = m_pSock->Send(m_pSendBuffer->GetData(), m_pSendBuffer->GetDataSize());
	cout << "Session::OnSockWrite send : " << iSend << " fd : " <<  GetFd() << endl;
	if ( iSend < 0 )
	{
		// Blocking errors are okay, just move on
		if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINPROGRESS )
		{
			return 0;
		}
		Close();
		return iSend;
	}

	m_pSendBuffer->RemoveData(iSend);
	return iSend;
}

int Session::Send(const char* pszData, uint32_t uBytes)
{
	int iSend = m_pSock->Send(pszData, uBytes);
	if(iSend < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINPROGRESS )
		{
			return 0;
		}
		Close();
		return iSend;
	}
	m_pSendBuffer->RemoveData(iSend);
	return iSend;
}

int Session::Handle(int events)
{
	if ( events & EPOLLIN )
		OnSockRead();
	if ( events & EPOLLOUT )
		OnSockWrite();

	return 0;
}

