#include <pthread.h>

#include "i_thread.h"

IThread::IThread() : m_tid(0),m_bRun(false)
{
}
IThread::~IThread()
{
}

bool IThread::StartThread()
{
	m_bRun = true;
	m_Info.pThread = this;
	int ret = pthread_create(&m_tid, NULL, ThreadFun, &m_Info);
	if(ret != 0)
		return false;
	
	return true;
}

bool IThread::StopThread()
{
	m_bRun = false;
	pthread_join(m_tid, NULL);
	return true;
}
