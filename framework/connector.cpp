#include "connector.h"
#include "logger_macro.h"
#include "server.h"
#include "header.pb.h"

#include <stdlib.h>
#include <iostream>

using namespace std;
Connector::Connector(const string& sName, Processor* pProcessor, int32_t iSessionNum)
{
	m_pProcessor = pProcessor;
	m_iCurIterNo = 0;
	m_iSessionNum = iSessionNum;
	m_ppSession = (Session**)malloc(sizeof(Session*)*m_iSessionNum);
	for( int i=0; i<m_iSessionNum; ++i)
		m_ppSession[i] = NULL;
	m_sName = sName;
}

Connector::~Connector()
{
	free(m_ppSession);
}

int Connector::Init(const string& sConnectHost, int32_t iConnectPort)
{
	m_sConnectHost = sConnectHost;
	m_iConnectPort = iConnectPort;
	LOG_DEBUG("Connector : " << sConnectHost << " : " << iConnectPort );
	return 0;
}

int Connector::Connect(int iIdx)
{
	Session* pSession = Server::Instance().GetIdleSessionMgr()->GetSession();
	if ( pSession == NULL ) 
	{
		LOG_ERROR("get idle connection error : ");
		return -1;
	}
	
	if (pSession->Connect(m_sConnectHost, m_iConnectPort, false) == -1)
    {
        LOG_ERROR("Connector::Connect, Connect failed, host " << m_sConnectHost <<
                  ", port " << m_iConnectPort);
        return -1;
    }

	if ( Server::Instance().GetEpoll().AddReadEvent(pSession->GetFd(), pSession) < 0 ) 
	{	
		pSession->Close();
		return -1;
	}

	pSession->SetBelongConnectorName(m_sName);
	pSession->SetProcessor(m_pProcessor);	
	m_ppSession[iIdx] = pSession;

	LOG_DEBUG("connect and set read event " << m_sConnectHost << ":" << m_iConnectPort <<  "fd:" << pSession->GetFd() << "idx:" << iIdx);

	return 0;
};

int Connector::Send(const char* pszData, uint32_t uSize)
{
	int iIdx = m_iCurIterNo++ % m_iSessionNum;

	if ( m_ppSession[iIdx] == NULL )
	{
		if ( Connect(iIdx) < 0 )	
		{
			LOG_DEBUG("Connector Send error");
			return -1;
		}
	}
	//如果非阻塞连接失败的话，会自动调用Connector::OnSessionClose把该连接设置为NULL，所以需要在使用前再判空一次
	if ( m_ppSession[iIdx] == NULL )
	{
		return -1;
	}
	
	return m_ppSession[iIdx]->Send(pszData, uSize);
}

void Connector::OnSessionClose(Session* pSession)
{
	for ( int i=0; i<m_iSessionNum; ++i )
	{
		if ( pSession == m_ppSession[i] )
		{
			LOG_DEBUG("OnSessionClose fd : " << m_ppSession[i]->GetFd() << ", idx : " << i);
			m_ppSession[i] = NULL;
			break;
		}
	}
}

