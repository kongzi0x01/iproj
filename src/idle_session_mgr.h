#ifndef IDLE_SESSION_MGR_H
#define IDLE_SESSION_MGR_H

#include "session.h"

#include <list>
#include <stdint.h>
using namespace std;

class IdleSessionMgr
{
public:
	IdleSessionMgr();
	~IdleSessionMgr();
	
public:
	Session* GetSession();
	bool PutSession(Session* pSession);
	uint32_t GetTotalNum(){	return m_SessionList.size();}
	
private:
	bool Grow(int num = 2);

private:
	list<Session*> m_SessionList;
	uint32_t m_iTotalNum;
};

#endif