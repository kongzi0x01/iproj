#include "service_svr_cmd_handle.h"
#include "proto_util.h"

int ServiceSvrCmdHandle::SendToDbSvr(google::protobuf::Message* pMsg)
{
	string sData;
	ProtoUtil::MakeData(m_pHeader, pMsg, sData);
	return Server::Instance().GetConnectorMgr()->Send("db_svr", sData.data(), sData.size());
}