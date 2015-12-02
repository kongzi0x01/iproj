#include "connector.h"
#include "logger_macro.h"
#include "server.h"
#include "header.pb.h"

#include <stdlib.h>
#include <iostream>

using namespace std;
Connector::Connector(const string& sName, Processor* pProcessor)
{
	m_pProcessor = pProcessor;
	m_pSession = NULL;
	m_sName = sName;
}

Connector::~Connector()
{
	m_pSession->Close();
}

int Connector::Init(const string& sConnectHost, int32_t iConnectPort)
{
	m_sConnectHost = sConnectHost;
	m_iConnectPort = iConnectPort;
	LOG_DEBUG("Connector : " << sConnectHost << " : " << iConnectPort );
	return 0;
}

int Connector::Connect()
{
	m_pSession = Server::Instance().GetIdleSessionMgr()->GetSession();
	if ( m_pSession == NULL ) 
	{
		LOG_ERROR("get idle connection error : ");
		return -1;
	}
		
	if (m_pSession->Connect(m_sConnectHost, m_iConnectPort) == -1)
    {
        LOG_ERROR("Connector::Connect, Connect failed, host " << m_sConnectHost <<
                  ", port " << m_iConnectPort);
        return -1;
    }

	if ( Server::Instance().GetEpoll().AddReadEvent(m_pSession->GetFd(), m_pSession) < 0 ) 
	{	
		m_pSession->Close();
		return -1;
	}

	m_pSession->SetBelongConnectorName(m_sName);
	m_pSession->SetProcessor(m_pProcessor);	
	
	LOG_DEBUG("******a new connect session . addr :" << m_pSession);

	return 0;
};

int Connector::Send(const char* pszData, uint32_t uSize)
{
	if ( m_pSession == NULL )
	{
		if ( Connect() < 0 )	
		{
			LOG_DEBUG("Connector Send error");
			return -1;
		}
	}
	//如果非阻塞连接失败的话，会自动调用Connector::OnSessionClose把该连接设置为NULL，所以需要在使用前再判空一次
	if ( m_pSession == NULL )
	{
		return -1;
	}
	
	return m_pSession->Send(pszData, uSize);
}

void Connector::OnSessionClose(Session* pSession)
{
	m_pSession->Close();
}

