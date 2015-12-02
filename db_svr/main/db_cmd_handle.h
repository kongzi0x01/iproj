#include "db_svr_cmd_handle.h"

class LoginReqHandle : public DbSvrCmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};

class RegistUserReqHandle :public DbSvrCmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};