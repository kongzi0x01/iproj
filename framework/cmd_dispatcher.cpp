#include "cmd_dispatcher.h"
#include "proto_util.h"
#include "logger_macro.h"

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
	LOG_DEBUG("Regist CmdHandle : " << pDesc->full_name());
}

int CmdDispatcher::Dispatch(const char* pszRequest, uint32_t uSize, Session* pRequestSourceSession)
{
	//decode request
	protocol::Msg msg;
	if ( !msg.ParseFromArray(pszRequest, uSize) )
	{
		LOG_DEBUG( "parse msg error" );
		return -1;
	}
	LOG_DEBUG("msg_full_name: " << msg.header().msg_full_name());
	//find google::protobuf::Descripor
	const google::protobuf::Descriptor* pDesc = DescriptorPool::generated_pool()->FindMessageTypeByName(msg.header().msg_full_name());

	if ( pDesc == NULL )
	{
		LOG_DEBUG( "can't find descriptor : " << msg.header().msg_full_name() );
		return -1;
	}
	
	Message* pMsg = NULL;
	const Message* pProtoType = MessageFactory::generated_factory()->GetPrototype(pDesc);
	if ( pProtoType == NULL)
	{	
		LOG_DEBUG( "can't find message proto type : " << pDesc->full_name() );
		return -1;
	}
 	
	pMsg = pProtoType->New();

	//find request'cmd handle
	CmdHandleMap::iterator iter = m_mCmdHandleMap.find(pDesc);
	if ( iter == m_mCmdHandleMap.end() )
	{
		LOG_DEBUG( "has no such cmd handle: " << pDesc->full_name() );
		delete pMsg;
		return -1;
	}

	//set some data, and dispatch cmd
	iter->second->SetSourceSession(pRequestSourceSession);
	iter->second->SetHeader(msg.mutable_header());

	if ( !pMsg->ParseFromString(msg.serialized_msg()) )
	{
		LOG_DEBUG( "message parse error " << pDesc->full_name() );
		delete pMsg;
		return -1;
	}

	int iRet = iter->second->Handle(pMsg);
	delete pMsg;
	return iRet;
}

