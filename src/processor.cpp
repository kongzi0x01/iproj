#include "processor.h"

#include <iostream>
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
	req.RemoveData(req.GetDataSize());
	return 0;
}