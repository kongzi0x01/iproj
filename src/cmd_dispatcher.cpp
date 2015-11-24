#include "cmd_dispatcher.h"
#include "proto_util.h"

#include <iostream>

using namespace std;
using namespace google::protobuf;

CmdDispatcher& CmdDispatcher::Instance()
{
	static CmdDispatcher g_sCmdDispatcher;
	return g_sCmdDispatcher;
}

CmdDispatcher::CmdDispatcher() : m_mCmdHandleMap(CMD_HANDLE_MAP_SIZE)
{
}

CmdDispatcher::~CmdDispatcher()
{
	CmdHandleMap::iterator iter = m_mCmdHandleMap.begin();
	for( ; iter != m_mCmdHandleMap.end(); ++iter )
	{
		delete iter->second;
	}
	m_mCmdHandleMap.clear();
}

void CmdDispatcher::Regist(const google::protobuf::Descriptor* pDesc, CmdHandle* pHandle)
{
	CmdHandleMap::iterator iter = m_mCmdHandleMap.find(pDesc);
	if ( iter != m_mCmdHandleMap.end() )
	{
		return ;
	}
	m_mCmdHandleMap[pDesc] = pHandle;
	cout << "Regist CmdHandle : " << pDesc->full_name() ;
}

int CmdDispatcher::Dispatch(const char* pszRequest, uint32_t uSize, Session* pRequestSourceSession)
{
	//decode request
	ProtoBasic basic;
	basic.Decode(pszRequest, uSize);
	
	protocol::Header header;
	if ( !header.ParseFromArray(pszRequest+sizeof(basic), basic.uHeaderLen) )
	{
		cout << "parse header error" << endl;
		return -1;
	}
	//find google::protobuf::Descripor
	const google::protobuf::Descriptor* pDesc = DescriptorPool::generated_pool()->FindMessageTypeByName(header.msg_full_name());

	if ( pDesc == NULL )
	{
		cout << "can't find descriptor : " << header.msg_full_name() << endl;;
		return -1;
	}
	
	Message* pMsg = NULL;
	const Message* pProtoType = MessageFactory::generated_factory()->GetPrototype(pDesc);
	if ( pProtoType == NULL)
	{	
		cout << "can't find message proto type : " << pDesc->full_name() << endl;
		return -1;
	}
 	
	pMsg = pProtoType->New();

	//find request'cmd handle
	CmdHandleMap::iterator iter = m_mCmdHandleMap.find(pDesc);
	if ( iter == m_mCmdHandleMap.end() )
	{
		cout << "has no such cmd handle: " << pDesc->full_name() << endl;
		delete pMsg;
		return -1;
	}

	//set some data, and dispatch cmd
	iter->second->SetSourceSession(pRequestSourceSession);
	iter->second->SetHeader(&header);
	uint32_t uBasicSize = sizeof(basic);
	uint32_t uCmdSize = uSize-basic.uHeaderLen-uBasicSize;
	const char* pszCmd = pszRequest + uBasicSize + basic.uHeaderLen;
	if ( uCmdSize != 0 )
	{
		if ( !pMsg->ParseFromArray(pszCmd, uCmdSize) )
		{
			cout << "message parse error " << pDesc->full_name() << endl;
			delete pMsg;
			return -1;
		}
	}

	int iRet = iter->second->Handle(pMsg);
	delete pMsg;
	return iRet;
}

