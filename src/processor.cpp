#include "processor.h"

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
	cout << "has receive data : " << req.GetData() << endl;
	session.Send(req.GetData(), req.GetDataSize());
	req.RemoveData(req.GetDataSize());
	
	return 0;
}