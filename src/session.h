#ifndef SESSION_H
#define SESSION_H

#include "epoll_handler.h"     
#include "circle_buffer.h"
#include "tcp_socket.h"   
#include "processor.h"

class Processor;

class Session : public EpollHandler
{
public:
    Session();
    ~Session();
	virtual int Handle(int events);

public:
	TcpSocket& GetTcpSocket(){return *m_pSock;}
	int GetFd() { return m_pSock->GetFd(); }
	void Close();
	
	int OnSockRead();
	int OnSockWrite();
	int Send(const char* pszData, uint32_t uBytes);
	CircleBuffer& GetSendBuffer(){return *m_pSendBuffer;}
	CircleBuffer& GetRecvBuffer(){return *m_pRecvBuffer;}
	void SetProcessor(Processor* pProcessor){m_pProcessor=pProcessor;}
	Processor* GetProcessor(){return m_pProcessor;}
	
private:
    TcpSocket* m_pSock;
	CircleBuffer* m_pSendBuffer;
	CircleBuffer* m_pRecvBuffer;
	Processor* m_pProcessor;
	
};

#endif
