#ifndef CMD_HANDLE_H
#define CMD_HANDLE_H

#include <stdint.h>
#include "header.pb.h"
#include "session.h"
#include "response_code.pb.h"
class Session;

class CmdHandle
{
public:
	CmdHandle();
	
	virtual int Handle(google::protobuf::Message* pMsg) = 0;

	int SendMsgBack(google::protobuf::Message* pCmdMsg);
	int SendMsgToSessionByIdent(google::protobuf::Message* pCmdMsg, uint64_t ident);
	
	//主动通知客户端消息，不能保证一定到达客户端
	int NotifyMsgBack(google::protobuf::Message* pCmdMsg);

	//设置请求来源的连接
	void SetSourceSession(Session* pSession);
	Session* GetSourceSession();

	void SetHeader(protocol::Header* pHeader);
	protocol::Header* GetHeader();

protected:
	protocol::Header* m_pHeader;
	Session* m_pSession;
};

class RegistSessionHandle : public CmdHandle
{
public:
	int Handle(google::protobuf::Message* pMsg);
};

#endif //_NETKIT_CMD_HANDLE_H_
