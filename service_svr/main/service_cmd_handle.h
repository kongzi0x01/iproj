#ifndef SERVICE_CMD_HANDLE_H
#define SERVICE_CMD_HANDLE_H

#include "service_svr_cmd_handle.h"

//登录
class LoginReqHandle : public ServiceSvrCmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};

class LoginRspHandle : public ServiceSvrCmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};

//注册用户
class RegistUserReqHandle :public ServiceSvrCmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};

class RegistUserRspHandle : public ServiceSvrCmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};

#endif