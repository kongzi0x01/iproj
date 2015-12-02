#ifndef DB_SVR_CMD_HANDLE_H
#define DB_SVR_CMD_HANDLE_H

#include "cmd_handle.h"
#include "header.pb.h"
#include "server.h"

class DbSvrCmdHandle : public CmdHandle
{
public:
	int SendToServiceSvr(google::protobuf::Message* pMsg);
};

#endif