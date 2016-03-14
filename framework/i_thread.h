#ifndef I_THREAD_H
#define I_THREAD_H

class IThread
{
public:
	IThread();
	~IThread();
	virtual bool StartThread();
	virtual bool StopThread();
	virtual bool RepeatedRun() = 0;
	
	bool IsRunning(){	return m_bRun;}
	
private:
	static void* ThreadFun(void* pData)
	{
		if(!pData)
		{
			return NULL;
		}
		ThreadInfo* pInfo = (ThreadInfo*)pData;
		IThread* pThread = pInfo->pThread;

		while(pThread->IsRunning())
		{
			if(pThread->RepeatedRun() == false)
				break;
		}
		return NULL;
	}
private:
	pthread_t m_tid;
	bool m_bRun;
	
	struct ThreadInfo
	{
		IThread* pThread;
	};
	
	ThreadInfo m_Info;
};

#endif