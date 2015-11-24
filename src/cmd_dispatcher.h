#ifndef CMD_DISPATCHER_H
#define CMD_DISPATCHER_H

#include "session.h"

#include <map>
#include <stdint.h>
#include <ext/hash_map>
#include "header.pb.h"
#include "proto_util.h"

using namespace std;
using namespace __gnu_cxx;

#define CMD_HANDLE_MAP_SIZE 4096

class Session;

class CmdDispatcher
{
public:
	static CmdDispatcher& Instance();
	CmdDispatcher();
	~CmdDispatcher();

	void Regist(const google::protobuf::Descriptor* pDesc, CmdHandle* pHandle);
	
	int Dispatch(const char* pszRequest, uint32_t uSize, Session* pRequestSourceSession);

private:
	CmdHandleMap m_mCmdHandleMap;
	
};

#define REGIST_CMD_HANDLE(MESSAGE_FULL_NAME, HANDLE_CLASS)\
{\
    static HANDLE_CLASS *pHandle = NULL;\
	if (NULL == pHandle)\
		pHandle = new HANDLE_CLASS();\
    CmdDispatcher::Instance().Regist(MESSAGE_FULL_NAME::descriptor(), pHandle);\
}\

#endif

