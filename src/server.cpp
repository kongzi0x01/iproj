#include "server.h"

Server::Server()
{}

Server::~Server()
{}

Server& Server::Instance()
{
	static Server instance;
	return instance;
}

int Server::Init(Accepter& accepter, const char* pszIP, int port)
{
	m_pAcceptedSessionMgr = new AcceptedSessionMgr();
	m_pIdleSessionMgr = new IdleSessionMgr();
	
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
