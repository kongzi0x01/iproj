#include "server.h"
#include "accepter.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string sListenAddr = "";
	int iListenPort = 8989;
	Accepter accepter;
	int ret = 0;
	ret = Server::Instance().Init(accepter, sListenAddr.c_str(), iListenPort);
	
	if(ret < 0)
	{
		cout << "Server init failed!" << endl;
		return -1;
	}
	
	Server::Instance().Run(10);
	return 0;
}
