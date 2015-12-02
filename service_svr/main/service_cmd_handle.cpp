#include "service_cmd_handle.h"
#include "line.pb.h"
#include "logger_macro.h"

int LoginReqHandle::Handle(google::protobuf::Message* pMsg)
{
	LOG_DEBUG("LoginReqHandle::Handle");
	
	line::LoginReq* req = dynamic_cast<line::LoginReq*>(pMsg);
	LOG_DEBUG( "user_name : " << req->user_name() << " encrypted_psw : " << req->encrypted_psw() );
	
	uint64_t client_session_ident = 
		Server::Instance().GetAcceptedSessionMgr()->GetIdentBySession(GetSourceSession());
	m_pHeader->set_client_session_ident(client_session_ident);
	LOG_DEBUG("client_session_ident : " << client_session_ident);
	
	return SendToDbSvr(req);
}

int LoginRspHandle::Handle(google::protobuf::Message* pMsg)
{
	LOG_DEBUG("LoginRspHandle::Handle");

	line::LoginRsp* rsp = dynamic_cast<line::LoginRsp*>(pMsg);
	
	LOG_DEBUG("client_session_ident : " << GetHeader()->client_session_ident());
	
	return SendMsgToSessionByIdent(rsp, GetHeader()->client_session_ident());
}

int RegistUserReqHandle::Handle(google::protobuf::Message* pMsg)
{
	LOG_DEBUG("RegistUserReqHandle::Handle");
	
	line::RegistUserReq* req = dynamic_cast<line::RegistUserReq*>(pMsg);
	LOG_DEBUG( "user_name : " << req->user_name() << " encrypted_psw : " << req->encrypted_psw() );
	
	return SendToDbSvr(req);
}

int RegistUserRspHandle::Handle(google::protobuf::Message* pMsg)
{
	LOG_DEBUG("RegistUserRspHandle::Handle");

	line::RegistUserRsp* rsp = dynamic_cast<line::RegistUserRsp*>(pMsg);
	
	return SendMsgToSessionByIdent(rsp, GetHeader()->client_session_ident());
}