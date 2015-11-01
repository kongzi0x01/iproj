#include "accepted_session_mgr.h"
#include "server.h"

#include "iostream"
using namespace std;

AcceptedSessionMgr::AcceptedSessionMgr(uint64_t iInitIdent)
{
	m_iCurIdent = iInitIdent;
}

AcceptedSessionMgr::~AcceptedSessionMgr()
{
	Ident2SessionMap::iterator iter = m_Ident2SessionMap.begin();
	for(; iter != m_Ident2SessionMap.end(); ++iter)
	{
		Session* pSession = iter->second;
		if(NULL != pSession)
		{
			delete pSession;
		}
	}
	m_Ident2SessionMap.clear();
	m_Session2IdentMap.clear();
}

bool AcceptedSessionMgr::AddSession(Session* pSession)
{
	if(NULL == pSession)
	{
		cout << "accepted session is null" <<endl;
		return false;
	}
	
	Session2IdentMap::iterator iter = m_Session2IdentMap.find(pSession);
	if(m_Session2IdentMap.end() != iter)
	{
		cout << "accepted session all ready exists " << endl;
		return false;
	}
	
	uint64_t iIdent = GetNewIdent();
	m_Ident2SessionMap[iIdent] = pSession;
	m_Session2IdentMap[pSession] = iIdent;
	m_iCurAcceptedSessionNum--;
	return true;
}

bool AcceptedSessionMgr::DelSession(uint64_t ident)
{
	Ident2SessionMap::iterator iter = m_Ident2SessionMap.find(ident);
	if(m_Ident2SessionMap.end() == iter)
	{
		cout << "AcceptedSessionMgr::DelSession: session not exists " << endl;
		return false;
	}
	m_Ident2SessionMap.erase(iter);
	m_Session2IdentMap.erase(iter->second);
	m_iCurAcceptedSessionNum--;
	return true;
}

bool AcceptedSessionMgr::DelSession(Session* pSession)
{
	Session2IdentMap::iterator iter = m_Session2IdentMap.find(pSession);
	if(m_Session2IdentMap.end() == iter)
	{
		cout << "AcceptedSessionMgr::DelSession: session not exists " << endl;
		return false;
	}
	m_Ident2SessionMap.erase(iter->second);
	m_Session2IdentMap.erase(iter);
	return true;
}

Session* AcceptedSessionMgr::GetSessionByIdent(uint64_t ident)
{
	Ident2SessionMap::iterator iter = m_Ident2SessionMap.find(ident);
	if(m_Ident2SessionMap.end() == iter)
	{
		cout << "AcceptedSessionMgr::GetSessionByIdent: session not exists " << endl;
		return NULL;
	}
	return iter->second;
}

uint64_t AcceptedSessionMgr::GetIdentBySession(Session* pSession)
{
	Session2IdentMap::iterator iter = m_Session2IdentMap.find(pSession);
	if(m_Session2IdentMap.end() == iter)
	{
		cout << "AcceptedSessionMgr::GetIdentBySession: session not exists " << endl;
		return 0;
	}
	return iter->second;
}

uint64_t AcceptedSessionMgr::GetNewIdent()
{
	return m_iCurIdent++;
}