#ifndef HTTP_MGR_H
#define HTTP_MGR_H

#include "server.h"
class HttpMgr
{
public:
	static HttpMgr& Instance()
	{
		static HttpMgr instance;
		return instance;
	}
	bool Init(const string& strAddr, uint16_t port);		
	bool StartService();	
	bool StopService();
	
private:
	HttpMgr();
	~HttpMgr();
	//声明复制构造函数和操作符=但不实现，防止调用
	HttpMgr(const HttpMgr& );
	const HttpMgr& operator = (const HttpMgr&);
	
	class Impl;
	Impl* m_pImpl;
};


#endif