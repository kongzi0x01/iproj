#include "proto_util.h"
#include "server.h"
#include "logger_macro.h"

#include <string.h>
#include <stdlib.h>
using namespace google::protobuf;

int ProtoUtil::SendToSession(Header* pHeader, Message* pMsg, Session* pSession)
{
	string sData;
	MakeData(pHeader, pMsg, sData);
	return pSession->Send(sData.data(), sData.size());
}

Message* ProtoUtil::CreateMessage(const string& sFullName)
{
	const Descriptor* pDesc = DescriptorPool::generated_pool()->FindMessageTypeByName(sFullName);

	if ( pDesc == NULL )
	{
		LOG_DEBUG( "can't find descriptor : " << sFullName );
		return NULL;
	}
	return CreateMessage(pDesc);
}

Message* ProtoUtil::CreateMessage(const Descriptor* pDesc)
{
	Message* pMsg = NULL;
	const Message* pProtoType = MessageFactory::generated_factory()->GetPrototype(pDesc);
	if ( pProtoType == NULL)
	{	
		LOG_DEBUG( "can't find message proto type : " << pDesc->full_name());
		return NULL;
	}
 	
	pMsg = pProtoType->New();
	return pMsg;
}

bool ProtoUtil::MakeData(Header* pHeader, Message* pMsg, string& sData)
{	
	protocol::Msg return_msg;
	return_msg.mutable_header()->CopyFrom(*pHeader);
	string str_serialized_msg;
	pMsg->SerializeToString(&str_serialized_msg);
	return_msg.set_serialized_msg(str_serialized_msg);
	return_msg.SerializeToString(&sData);

	return true;
}
