#include "server.h"
#include "accepter.h"
#include "cmd_dispatcher.h"
#include "db_cmd_handle.h"
#include "line.pb.h"
#include "logger_macro.h"
#include "db_mgr.h"
#include "processor.h"

#include <iostream>
#include <string>
#include <log4cplus/configurator.h>

using namespace log4cplus;
using namespace std;

int RegistCmdHandle();

int main()
{
	string sListenAddr = "";
	int iListenPort = 7979;
	
	//注册消息响应函数
	RegistCmdHandle();
	
	//log4cplus配置日志文件路径
	PropertyConfigurator::doConfigure("../conf/log4cplus.conf");
	
	//初始化数据库
	string db = "Iproj";
	string host = "127.0.0.1";
	int port = 3306;
	string user = "fuzi";
	string password = "123456";
	if(!DbMgr::Instance().Init(host, port, db, user, password))
	{
		return -1;
	}
	
	LOG_DEBUG("server start...");
	
	Accepter accepter;
	int ret = 0;
	ret = Server::Instance().Init(accepter, sListenAddr.c_str(), iListenPort);
	
	if(ret < 0)
	{
		LOG_ERROR("Server init failed!");
		return -1;
	}
	
	Processor connector_processor;
	Server::Instance().GetConnectorMgr()->AddConnector("service_svr", "127.0.0.1", 8989, &connector_processor);
	
	Server::Instance().Run(10);
	return 0;
}

int RegistCmdHandle()
{
	REGIST_CMD_HANDLE(line::LoginReq, LoginReqHandle);
	REGIST_CMD_HANDLE(line::RegistUserReq, RegistUserReqHandle);
	return 0;
}
