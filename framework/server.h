#ifndef SERVER_H
#define SERVER_H

#include "my_epoll.h"
#include "accepter.h"
#include "accepted_session_mgr.h"
#include "idle_session_mgr.h"
#include "connector_mgr.h"

class Server
{
public:
	Server();
	~Server();

	static Server& Instance();

public:
	int Init(Accepter& accepter, const char* pszIP, int port);
	int Run(int timeout_ms);
	Epoll& GetEpoll(){	return m_epoll;}
	AcceptedSessionMgr* GetAcceptedSessionMgr(){	return m_pAcceptedSessionMgr;}
	IdleSessionMgr* GetIdleSessionMgr(){	return m_pIdleSessionMgr;}
	ConnectorMgr* GetConnectorMgr(){	return m_pConnectorMgr;}
	
private:
	Epoll m_epoll;
	AcceptedSessionMgr* m_pAcceptedSessionMgr;
	IdleSessionMgr* m_pIdleSessionMgr;
	ConnectorMgr* m_pConnectorMgr;
};

#endif
