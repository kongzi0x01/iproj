#include "proto_util.h"
#include "server.h"
#include "logger_macro.h"

#include <string.h>
#include <stdlib.h>
using namespace google::protobuf;

/*ProtoBasic::ProtoBasic(uint32_t uPackLen, uint32_t uHeaderLen)
{
	this->uPackLen = uPackLen;
	this->uHeaderLen = uHeaderLen;
}

int ProtoBasic::Decode(const char* pszData, uint32_t uSize)
{
	if ( uSize < sizeof(ProtoBasic) )
	{
		//LOG_DEBUG("DecodeBasic error, size : " << uSize);
		return -1;
	}

	uPackLen = *((uint32_t*)pszData);
	uHeaderLen = *((uint32_t*)(pszData+sizeof(uint32_t)));
	LOG_DEBUG( "uPackLen : " << uPackLen << ", uHeaderLen : " << uHeaderLen );	
	return 0;	
}
*/
int ProtoUtil::SendToSession(Header* pHeader, Message* pMsg, Session* pSession)
{
	string sData;
	MakeData(pHeader, pMsg, sData);
	return pSession->Send(sData.data(), sData.size());
}

/*int ProtoUtil::Code(const char* pszHeader, uint32_t uHeaderLen, const char* pszCmd, uint32_t uCmdLen, string& sOut)
{
	ProtoBasic basic;
	uint16_t uBasicLen = sizeof(basic);
	basic.uHeaderLen = uHeaderLen;
	basic.uPackLen = uHeaderLen + uCmdLen + uBasicLen;	

	sOut.clear();
	sOut.append((const char*)(&basic), uBasicLen);	
	sOut.append(pszHeader, uHeaderLen);
	sOut.append(pszCmd, uCmdLen);
	return 0;
}*/

/*int ProtoUtil::Decode(const char* pszPackData, uint32_t uPackLen, string& sOutHeader, string& sOutCmd)
{
	ProtoBasic basic;
	uint16_t uBasicLen = sizeof(basic);
	//memcpy(&basic, pszPackData, uBasicLen);	
	basic.uPackLen = *((uint32_t*)pszPackData);
	basic.uHeaderLen = *((uint32_t*)(pszPackData+sizeof(uint32_t)));

	if ( basic.uHeaderLen >= uPackLen - uBasicLen )
		return -1;

	sOutHeader.assign(pszPackData+uBasicLen, basic.uHeaderLen);	
	
	const char* pszCmd = pszPackData + uBasicLen + basic.uHeaderLen;
	uint32_t uCmdLen = uPackLen - basic.uHeaderLen - uBasicLen;
	sOutCmd.assign(pszCmd, uCmdLen);
	
	return 0;
}*/

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