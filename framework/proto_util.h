#ifndef NETKIT_PROTOCOL_H
#define NETKIT_PROTOCOL_H

#include <stdint.h>
#include <string>
#include "session.h"
#include "header.pb.h"
#include "cmd_handle.h"
#include <ext/hash_map>

using namespace std;
using namespace protocol;
using namespace google::protobuf;
using namespace __gnu_cxx;


const uint32_t MAX_PACKAGE_LEN = 1024*1024;

class ProtoUtil
{
public:
	//发送消息到指定的session
	static int SendToSession(Header* pHeader, Message* pMsg, Session* pSession);

	//发送消息到指定ident的接入CS协议的session
	//uIdent == 0 表示发送到任意session
	static int SendToAcceptSession(Header* pHeader, Message* pMsg, uint64_t uIdent = 0);

	//发送消息到regist过的session
	static int SendToRegistSession(Header* pHeader, Message* pMsg, const string& sRegistName);

	//发送消息到指定的connector对应的任意session
	static int SendToConnector(Header* pHeader, Message* pMsg, const string& sConnectorName);

	static int Code(const char* pszHeader, uint32_t uHeaderLen, const char* pszCmd, uint32_t uCmdLen, string& sOut);

	static int Decode(const char* pszPackData, uint32_t uPackLen, string& sOutHeader, string& sOutCmd);

	static Message* CreateMessage(const string& sFullName);	
	static Message* CreateMessage(const Descriptor* pDesc);

	static bool MakeData(Header* pHeader, Message* pMsg, string& sData);
	//ProtoBasic m_basic;
};

struct HashDescriptorPointor
{       
	size_t operator()(const Descriptor* const & ref) const{ 
		return (size_t)ref;                                                                   
	}                                                                                         
};                                                                                            

struct EqualDescriptorPointor
{   
	size_t operator()(const Descriptor* const & l, const Descriptor* const & r) const{
		return r == l;                                                                        
	}
};

typedef hash_map<const Descriptor*, CmdHandle*, HashDescriptorPointor, EqualDescriptorPointor> CmdHandleMap;


#endif

