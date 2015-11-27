#ifndef SERVICE_CMD_HANDLE_H
#define SERVICE_CMD_HANDLE_H

#include "cmd_handle.h"

class LoginReqHandle : public CmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};

#endif