#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "tcp_socket.h"
#include "session.h"
#include "processor.h"
#include <string>

using namespace std;

class Connector
{
public:
	Connector(const string& sName, Processor* pProcessor, int32_t iSessionNum = 4);
	~Connector();

	int Init(const string& sConnectHost, int32_t iConnectPort);
	
	int Send(const char* pszData, uint32_t uSize);

	void OnSessionClose(Session* pSession);	

	int Connect(int iIdx);

	void SetProcessor(Processor* pProcessor)
	{
		m_pProcessor = pProcessor;
	}

private:
	string m_sConnectHost;
	int32_t m_iConnectPort;
	Session** m_ppSession;
	int32_t m_iSessionNum;
	int32_t m_iCurIterNo; 
	Processor* m_pProcessor;
	string m_sName;
};

#endif

