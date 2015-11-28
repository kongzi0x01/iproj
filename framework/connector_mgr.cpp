#include "connector_mgr.h"
#include "logger_macro.h"

using namespace std;

ConnectorMgr::ConnectorMgr()
{
}

ConnectorMgr::~ConnectorMgr()
{
	ConnectorMap::iterator iter = m_mapConnector.begin();
	for ( ; iter!= m_mapConnector.end(); ++iter )
	{
		delete iter->second;
	}
	m_mapConnector.clear();
}

int ConnectorMgr::AddConnector(const string& sConnectorName, const string& sHost, int32_t iPort, Processor* pProcessor, int iConnNum)
{
	ConnectorMap::iterator iter = m_mapConnector.find(sConnectorName);
	if ( iter != m_mapConnector.end() )
	{
		LOG_ERROR(__FUNCTION__ << "connector exist : " << sConnectorName 
			<< " ,ip :" << sHost << ", prot : " << iPort);
		return -1;
	}

	Connector* pConnector = new Connector(sConnectorName, pProcessor, iConnNum);
	if ( pConnector->Init(sHost, iPort) < 0 )
		return -1;

	m_mapConnector[sConnectorName] = pConnector;
	return	0;
}

int ConnectorMgr::Send(const string& sConnectorName, const char* pszData, uint32_t uSize)
{
	ConnectorMap::iterator iter = m_mapConnector.find(sConnectorName);
	if ( iter == m_mapConnector.end() )
		return -1;
	//LOG_DEBUG(__FUNCTION__ << "")
	return iter->second->Send(pszData, uSize);
}

void ConnectorMgr::OnSessionClose(Session* pSession)
{
	const string& sName = pSession->GetBelongConnectorName();
	ConnectorMap::iterator iter = m_mapConnector.find(sName);
	if ( iter == m_mapConnector.end() )
		return ;
	return iter->second->OnSessionClose(pSession);
}

int ConnectorMgr::SetProcessor(const string& sConnectorName, Processor* pProcessor)
{
	//string sKey = GetKey(pSession->GetRemoteHost(), pSession->GetRemotePort());
	ConnectorMap::iterator iter = m_mapConnector.find(sConnectorName);
	if ( iter == m_mapConnector.end() )
		return -1;
	iter->second->SetProcessor(pProcessor);
	return 0;
}

string ConnectorMgr::GetKey(const string& sHost, int32_t iPort)
{
	char szTmp[32];
	sprintf(szTmp, "%s:%d", sHost.c_str(), iPort);
	return string(szTmp);
}


