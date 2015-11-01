#include "idle_session_mgr.h"

#include <iostream>
using namespace std;

IdleSessionMgr::IdleSessionMgr()
{
	m_iTotalNum = 0;
	Grow();
}

IdleSessionMgr::~IdleSessionMgr()
{
	while( !m_SessionList.empty() )
	{
		Session* pSession = m_SessionList.back();
		delete pSession;
		m_SessionList.pop_back();
	}
}

Session* IdleSessionMgr::GetSession()
{
	if( m_SessionList.empty() )
	{
		Grow();
	}
	Session* pSession = m_SessionList.back();
	m_SessionList.pop_back();
	return pSession;
}

bool IdleSessionMgr::PutSession(Session* pSession)
{
	if(NULL != pSession)
	{
		m_SessionList.push_back(pSession);
	}
	return true;
}

bool IdleSessionMgr::Grow(int num)
{
	cout << "IdleSessionMgr::Grow" << endl;
	int failed_num = 0;
	for(int i = 0; i < num; i++)
	{
		Session* pSession = new Session();
		if(NULL == pSession)
		{
			failed_num++;
			continue;
		}
		m_SessionList.push_back(pSession);
		m_iTotalNum++;
	}
	
	cout << "total:" << m_iTotalNum << " failed:" << failed_num << endl;
	return true;
}