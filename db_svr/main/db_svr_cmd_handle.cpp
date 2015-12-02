#include "db_svr_cmd_handle.h"
#include "proto_util.h"
#include "logger_macro.h"

int DbSvrCmdHandle::SendToServiceSvr(google::protobuf::Message* pMsg)
{
	string sData;
	ProtoUtil::MakeData(m_pHeader, pMsg, sData);
	
	LOG_DEBUG("client_session_ident : " << GetHeader()->client_session_ident());
	
	return Server::Instance().GetConnectorMgr()->Send("service_svr", sData.data(), sData.size());
}