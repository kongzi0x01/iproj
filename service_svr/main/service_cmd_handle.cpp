#include "service_cmd_handle.h"
#include "line.pb.h"
#include "logger_macro.h"

int LoginReqHandle::Handle(google::protobuf::Message* pMsg)
{
	LOG_DEBUG("LoginReqHandle::Handle");
	
	line::LoginReq* req = dynamic_cast<line::LoginReq*>(pMsg);
	LOG_DEBUG( "user_name : " << req->user_name() << " encrypted_psw : " << req->encrypted_psw() );
	
	SendToDbSvr(req);
	
	line::LoginRsp rsp;
	rsp.set_result(100);
	return SendMsgBack(&rsp);
}