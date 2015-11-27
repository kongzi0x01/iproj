#include "processor.h"
#include "proto_util.h"
#include "cmd_dispatcher.h"
#include "logger_macro.h"

#include <string>
using namespace std;

Processor::Processor()
{
}

Processor::~Processor()
{
}

int Processor::Deal(Session& session)
{
	LOG_DEBUG( "Processor::Deal" );
	
	CircleBuffer& req = session.GetRecvBuffer();
	if(req.GetDataSize() < 0)
	{
		return -1;
	}
	return HandleRequest(req.GetData(), req.GetDataSize(), session);
}

int Processor::HandleRequest(const char* pszRequest, uint32_t uSize, Session& session)
{
	return CmdDispatcher::Instance().Dispatch(pszRequest, uSize, &session);
}