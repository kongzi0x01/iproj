#ifndef SERVICE_SVR_CMD_HANDLE_H
#define SERVICE_SVR_CMD_HANDLE_H

#include "cmd_handle.h"

class ServiceSvrCmdHandle : public CmdHandle
{
public:
	int SendToDbSvr(google::protobuf::Message* pMsg);
};

#endif