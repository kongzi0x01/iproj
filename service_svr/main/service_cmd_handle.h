#ifndef SERVICE_CMD_HANDLE_H
#define SERVICE_CMD_HANDLE_H

#include "service_svr_cmd_handle.h"

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
#endif