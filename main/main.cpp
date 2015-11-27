#include "server.h"
#include "accepter.h"
#include "cmd_dispatcher.h"
#include "service_cmd_handle.h"
#include "line.pb.h"
#include "logger_macro.h"

#include <iostream>
#include <string>
#include <log4cplus/configurator.h>

using namespace log4cplus;

int RegistCmdHandle();

int main()
{
	string sListenAddr = "";
	int iListenPort = 8989;
	
	//注册消息响应函数
	RegistCmdHandle();
	
	//log4cplus配置日志文件路径
	PropertyConfigurator::doConfigure("../conf/log4cplus.conf");
	
	LOG_DEBUG("server start...");
	
	Accepter accepter;
	int ret = 0;
	ret = Server::Instance().Init(accepter, sListenAddr.c_str(), iListenPort);
	
	if(ret < 0)
	{
		LOG_ERROR("Server init failed!");
		return -1;
	}
	
	
	
	Server::Instance().Run(10);
	return 0;
}

int RegistCmdHandle()
{
	REGIST_CMD_HANDLE(line::LoginReq, LoginReqHandle);
	
	return 0;
}