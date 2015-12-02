#include "cmd_handle.h"
#include "proto_util.h"
#include "server.h"
#include "logger_macro.h"

CmdHandle::CmdHandle()
{
	m_pSession = NULL;
	m_pHeader = NULL;
}

int CmdHandle::SendMsgBack(google::protobuf::Message* pCmdMsg)
{
	return ProtoUtil::SendToSession(m_pHeader, pCmdMsg, m_pSession);
}

int CmdHandle::SendMsgToSessionByIdent(google::protobuf::Message* pCmdMsg, uint64_t ident)
{	
	Session* pSession = Server::Instance().GetAcceptedSessionMgr()->GetSessionByIdent(ident);
	if(!pSession)
	{
		LOG_ERROR("GetSessionByIdent failded! ident : " << ident);
		return -1;
	}
	SetSourceSession(pSession);
	return ProtoUtil::SendToSession(m_pHeader, pCmdMsg, m_pSession);
}

//主动通知客户端消息，不能保证一定到达客户端
int CmdHandle::NotifyMsgBack(google::protobuf::Message* pCmdMsg)
{
	Header header(*m_pHeader);

	return ProtoUtil::SendToSession(&header, pCmdMsg, m_pSession);
}

void CmdHandle::SetSourceSession(Session* pSession)
{
	m_pSession = pSession;
}

void CmdHandle::SetHeader(protocol::Header* pHeader)
{
	m_pHeader = pHeader;
}

Session* CmdHandle::GetSourceSession()
{
	return m_pSession;
}

protocol::Header* CmdHandle::GetHeader()
{
	return m_pHeader;
}
