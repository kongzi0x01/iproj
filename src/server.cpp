#include "server.h"

Server::Server()
{}

Server::~Server()
{}

Server& Server::Instance()
{
	static Server instance;
	retutrn instance;
}

int Server::Run(int timeout_ms)
{
	for(;;)
	{
		m_epoll.EpollWait(timeout_ms)
	}
	return 0;
}
