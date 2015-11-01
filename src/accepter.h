#ifndef ACCEPTER_H
#define ACCEPTER_H

#include "epoll_handler.h"
#include "tcp_socket.h"

class Accepter: public EpollHandler
{
public:
	Accepter();
	~Accepter();
	
public:
	int Init(const char* pszIP, int port);
	virtual int Handle(int event);  
	
private:
	TcpSocket* m_pTcpSock;
};

#endif
