#include "server.h"
#include "accepter.h"
#include "cmd_dispatcher.h"
#include "service_cmd_handle.h"
#include "line.pb.h"
#include "logger_macro.h"
#include "processor.h"

#include <iostream>
#include <string>
#include <log4cplus/configurator.h>

#include "http_mgr.h"

using namespace log4cplus;

int RegistCmdHandle();

int main()
{
	string sListenAddr = "";
	int iListenPort = 8989;
	string httpAddr("0.0.0.0");
	uint16_t httpPort = 9090;
	
	//注册消息响应函数
	RegistCmdHandle();
	
	//log4cplus配置日志文件路径
	PropertyConfigurator::doConfigure("../conf/log4cplus.conf");
	
	LOG_DEBUG("server start...");
	
	//启动HTTP服务器
	HttpMgr::Instance().Init(httpAddr, httpPort);
	HttpMgr::Instance().StartService();
	
	Accepter accepter;
	int ret = 0;
	ret = Server::Instance().Init(accepter, sListenAddr.c_str(), iListenPort);
	
	if(ret < 0)
	{
		LOG_ERROR("Server init failed!");
		return -1;
	}
	Processor connector_processor;
	Server::Instance().GetConnectorMgr()->AddConnector("db_svr", "127.0.0.1", 7979, &connector_processor);
	
	Server::Instance().Run(10);
	return 0;
}

int RegistCmdHandle()
{
	REGIST_CMD_HANDLE(line::LoginReq, LoginReqHandle);
	REGIST_CMD_HANDLE(line::LoginRsp, LoginRspHandle);
	REGIST_CMD_HANDLE(line::RegistUserReq, RegistUserReqHandle);
	REGIST_CMD_HANDLE(line::RegistUserRsp, RegistUserRspHandle);
	
	return 0;
}