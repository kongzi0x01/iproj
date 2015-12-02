#include "db_cmd_handle.h"
#include "line.pb.h"
#include "logger_macro.h"
#include "db_mgr.h"

int LoginReqHandle::Handle(google::protobuf::Message* pMsg)
{
	LOG_DEBUG("LoginReqHandle::Handle");
	
	line::LoginReq* req = dynamic_cast<line::LoginReq*>(pMsg);
	LOG_DEBUG( "user_name : " << req->user_name() << " encrypted_psw : " << req->encrypted_psw() );
	
	line::LoginRsp rsp;

	line::UserData* pUserData = DbMgr::Instance().FindUserByUsername(req->user_name());
	if(!pUserData)
	{
		rsp.set_result(line::ERR_NOT_FOUND_USER);
	}
	else
	{
		if(pUserData->encrypted_psw() == req->encrypted_psw())
		{
			rsp.set_result(line::OK);
		}
		else
		{
			rsp.set_result(line::ERR_WROND_PASSWORD);
		}
	}
	
	//返回时假如消息不一样了，需要修改header中的msg_full_name
	protocol::Header* pHeader = GetHeader();
	pHeader->set_msg_full_name("line.LoginRsp");
	
	return SendToServiceSvr(&rsp);
}

int RegistUserReqHandle::Handle(google::protobuf::Message* pMsg)
{
	LOG_DEBUG("RegistUserReqHandle::Handle");
	line::RegistUserReq* req = dynamic_cast<line::RegistUserReq*>(pMsg);
	LOG_DEBUG( "user_name : " << req->user_name() << " encrypted_psw : " << req->encrypted_psw() );
	
	
	line::LoginRsp rsp;

	line::UserData* pUserData = DbMgr::Instance().FindUserByUsername(req->user_name());
	if(pUserData != NULL)
	{
		rsp.set_result(line::ERR_USERNAME_EXISTS);
	}
	else
	{
		line::UserData user_data;
		user_data.set_user_id(0);	//新建用户时设置id为0，由DbMgr自动分配
		user_data.set_user_name(req->user_name());
		user_data.set_encrypted_psw(req->encrypted_psw());
		
		if( !DbMgr::Instance().AddUserData(&user_data))
		{
			rsp.set_result(line::ERR_SYSTEM);
		}
		else
		{
			rsp.set_result(line::OK);
		}
	}
	
	//返回时假如消息不一样了，需要修改header中的msg_full_name
	protocol::Header* pHeader = GetHeader();
	pHeader->set_msg_full_name("line.RegistUserRsp");
	
	return SendToServiceSvr(&rsp);
}
