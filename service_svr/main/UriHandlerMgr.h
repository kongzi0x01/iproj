#ifndef REGIST_URI_HANDLER_CPP
#define REGIST_URI_HANDLER_CPP
#include <event2/http.h>
#include <event2/http_struct.h>
#include <map>
#include <string>
using std::map;
using std::string;

typedef void (UriHandler)(struct evhttp_request*, void*);
typedef map<string, UriHandler*> UriHandlerMap;

class UriHandlerMgr
{
public:
	static UriHandlerMgr& Instance()
	{
		static UriHandlerMgr instance;
		return instance;
	}
	void Regist(string strUri, UriHandler* uriHandler);
	UriHandler* GetUriHandler(string strUri);
protected:
	~UriHandlerMgr();
	
private:
	//私有构造函数
	UriHandlerMgr();
	//声明复制构造函数和操作符“=”但不实现，预防调用
	UriHandlerMgr(UriHandlerMgr&);
	UriHandlerMgr& operator=(UriHandlerMgr&);

	UriHandlerMap m_UriHandlerMap;
};

#endif
