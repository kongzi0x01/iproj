#ifndef SERVER_H
#define SERVER_H

#include "my_epoll.h"

class Server
{
public:
	Server();
	~Server();

	static Server& Instance();

public:
	int Run(int timeout_ms);


private:
	Epoll m_epoll;
}

#endif
