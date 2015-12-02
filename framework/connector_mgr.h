#ifndef CONNECTOR_MGR_H
#define CONNECTOR_MGR_H

#include "connector.h"
#include "processor.h"
#include <string>
#include <map>

using namespace std;
using namespace __gnu_cxx;

typedef map<string, Connector*> ConnectorMap;

class ConnectorMgr
{
public:
	ConnectorMgr();
	~ConnectorMgr();

	int AddConnector(const string& sConnectorName, const string& sHost, int32_t iPort, Processor* pProcessor);
	
	int Send(const string& sConnectorName, const char* pszData, uint32_t uSize);

	void OnSessionClose(Session* pSession);	

	int SetProcessor(const string& sConnectorName, Processor* pProcessor); 

private:
	string GetKey(const string& sHost, int32_t iPort);

private:
	//map<string, Connector*> m_mapConnector;
	ConnectorMap m_mapConnector;
};

#endif

