#include "accepted_session_mgr.h"
#include "server.h"
#include "logger_macro.h"

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
		LOG_DEBUG( "accepted session is null" );
		return false;
	}
	
	Session2IdentMap::iterator iter = m_Session2IdentMap.find(pSession);
	if(m_Session2IdentMap.end() != iter)
	{
		LOG_DEBUG( "accepted session all ready exists " );
		return false;
	}
	LOG_DEBUG("******add new accepted session . addr :" << pSession);
	uint64_t iIdent = GetNewIdent();
	m_Ident2SessionMap[iIdent] = pSession;
	m_Session2IdentMap[pSession] = iIdent;
	m_iCurAcceptedSessionNum--;
	
	LOG_DEBUG("GetCurAcceptedNum() : " << GetCurAcceptedNum());
	return true;
}

bool AcceptedSessionMgr::DelSession(uint64_t ident)
{
	Ident2SessionMap::iterator iter = m_Ident2SessionMap.find(ident);
	if(m_Ident2SessionMap.end() == iter)
	{
		LOG_DEBUG( "AcceptedSessionMgr::DelSession: session not exists " );
		return false;
	}
	LOG_DEBUG("DelSession session. ident : " << ident);
	m_Ident2SessionMap.erase(iter);
	m_Session2IdentMap.erase(iter->second);
	m_iCurAcceptedSessionNum--;
	return true;
}

bool AcceptedSessionMgr::DelSession(Session* pSession)
{
	LOG_DEBUG("******del accepted session . addr :" << pSession);
	Session2IdentMap::iterator iter = m_Session2IdentMap.find(pSession);
	if(m_Session2IdentMap.end() == iter)
	{
		LOG_DEBUG( "AcceptedSessionMgr::DelSession: session not exists " );
		return false;
	}
	LOG_DEBUG("DelSession session. ident : " << iter->first);
	m_Ident2SessionMap.erase(iter->second);
	m_Session2IdentMap.erase(iter);
	
	LOG_DEBUG("GetCurAcceptedNum() : " << GetCurAcceptedNum());
	return true;
}

Session* AcceptedSessionMgr::GetSessionByIdent(uint64_t ident)
{
	Ident2SessionMap::iterator iter = m_Ident2SessionMap.find(ident);
	if(m_Ident2SessionMap.end() == iter)
	{
		LOG_DEBUG( "AcceptedSessionMgr::GetSessionByIdent: session not exists " );
		return NULL;
	}
	
	LOG_DEBUG("GetCurAcceptedNum() : " << GetCurAcceptedNum());
	return iter->second;
}

uint64_t AcceptedSessionMgr::GetIdentBySession(Session* pSession)
{
	Session2IdentMap::iterator iter = m_Session2IdentMap.find(pSession);
	if(m_Session2IdentMap.end() == iter)
	{
		LOG_DEBUG( "AcceptedSessionMgr::GetIdentBySession: session not exists " );
		return 0;
	}
	return iter->second;
}

uint64_t AcceptedSessionMgr::GetNewIdent()
{
	return m_iCurIdent++;
}