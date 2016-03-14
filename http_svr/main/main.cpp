#include "http_mgr.h"
#include "logger_macro.h"

#include <log4cplus/configurator.h>
#include <string>
using namespace log4cplus;
using std::string;

int main()
{
	//log4cplus配置日志文件路径
	PropertyConfigurator::doConfigure("../conf/log4cplus.conf");
	
	LOG_DEBUG("http_svr start.");
	
	string strAddr("0.0.0.0");
	uint16_t port = 8989;
	HttpMgr::Instance().Init(strAddr, port);
	HttpMgr::Instance().StartService();
	while(true)
	{}
	return 0;
}
