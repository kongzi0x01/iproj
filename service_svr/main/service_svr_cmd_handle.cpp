#include "service_svr_cmd_handle.h"
#include "proto_util.h"
#include "server.h"

int ServiceSvrCmdHandle::SendToDbSvr(google::protobuf::Message* pMsg)
{
	string sData;
	
	uint64_t client_session_ident = 
		Server::Instance().GetAcceptedSessionMgr()->GetIdentBySession(GetSourceSession());
	m_pHeader->set_client_session_ident(client_session_ident);
	
	ProtoUtil::MakeData(m_pHeader, pMsg, sData);
	return Server::Instance().GetConnectorMgr()->Send("db_svr", sData.data(), sData.size());
}