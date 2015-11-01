#ifndef ACCEPTER_SESSION_MGR_H
#define ACCEPTER_SESSION_MGR_H

#include "session.h"
#include "accepter.h"

#include <map>
#include <stdint.h>
using namespace std;

//ident 为每个session的标志
typedef map<uint64_t /*ident*/, Session* /*accepted session*/> Ident2SessionMap;
typedef map<Session* /*accepted session*/, uint64_t /*ident*/> Session2IdentMap;

class AcceptedSessionMgr
{
public:
	AcceptedSessionMgr(uint64_t iInitIdent = 100000);
	~AcceptedSessionMgr();

public:
	bool AddSession(Session* pSession);
	bool DelSession(uint64_t ident);
	bool DelSession(Session* pSession);
	Session* GetSessionByIdent(uint64_t ident);
	uint64_t GetIdentBySession(Session* pSession);
	
	int Send(const char* pMsg, uint32_t size, uint64_t ident);	//TODO
	int SendAll(const char* pMsg, uint32_t size);	//TODO
	
	uint32_t GetCurAcceptedNum(){	return m_Ident2SessionMap.size();}
	
private:
	uint64_t GetNewIdent();
	
private:
	Ident2SessionMap m_Ident2SessionMap;
	Session2IdentMap m_Session2IdentMap;
	uint64_t m_iCurIdent;
	uint32_t m_iCurAcceptedSessionNum;
};

#endif