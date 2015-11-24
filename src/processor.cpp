#include "processor.h"
#include "proto_util.h"
#include "cmd_dispatcher.h"

#include <iostream>
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
	cout << "Processor::Deal" << endl;
	
	CircleBuffer& req = session.GetRecvBuffer();
	
	ProtoBasic stProtoBasic;	
	//a demo to show how to parse binary protocol
	while ( stProtoBasic.Decode(req.GetData(), req.GetDataSize()) == 0 )
	{		
		if ( stProtoBasic.uPackLen < sizeof(stProtoBasic) + stProtoBasic.uHeaderLen )
		{
			cout << "request package error , packlen: " 
				<< stProtoBasic.uPackLen
				<< ", headerlen : "
				<< stProtoBasic.uHeaderLen
				<< "basic len : " 
				<< sizeof(stProtoBasic) << endl;
			return -1;
		
		}
	
		if ( req.GetDataSize() >= stProtoBasic.uPackLen )	
		{//数据足够构成一个request, 下一次循环再继续分析请求数据
			if ( HandleRequest(req.GetData(), stProtoBasic.uPackLen, session) < 0 ) 
				return -1;
		
			req.RemoveData(stProtoBasic.uPackLen);
		}
		else
		{//不够数据，等待下一次有数据进来再分析
			break;
		}
	}
	return 0;
}

int Processor::HandleRequest(const char* pszRequest, uint32_t uSize, Session& session)
{
	return CmdDispatcher::Instance().Dispatch(pszRequest, uSize, &session);
}