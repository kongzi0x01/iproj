#include <event2/http.h>
#include <event2/event.h>
#include <event2/http_struct.h>
#include <event.h>
#include <unistd.h>
#include <string>

#include "logger_macro.h"
#include "i_thread.h"
#include "http_mgr.h"
#include "UriHandlerMgr.h"

using std::string;

class HttpMgr::Impl : public IThread
{
private:
	struct event_base* m_pBase;
	struct evhttp* m_pHttp;
	string m_listenAddr;
	uint16_t m_listenPort;	

public:
	Impl();
	~Impl();
	bool Init(const string& strAddr, uint16_t port);
	virtual bool RepeatedRun();
	void RegistUrlHandler(struct evhttp* pEvhttp);
	
	//handlers
	static void Cb_Base(struct evhttp_request *request, void *arg);
};

HttpMgr::Impl::Impl() : m_pBase(NULL), m_pHttp(NULL)
{}

HttpMgr::Impl::~Impl()
{
	if(m_pHttp != NULL)
	{
		evhttp_free(m_pHttp);
	}
	
	if(m_pBase != NULL)
	{
		event_base_free(m_pBase);
	}
}

bool HttpMgr::Impl::Init(const string& strAddr, uint16_t port)
{
	m_listenAddr = strAddr;
	m_listenPort = port;
	m_pBase = event_base_new();
	m_pHttp = evhttp_new(m_pBase);
	return true;
}

bool HttpMgr::Impl::RepeatedRun()
{
	//监听HTTP请求
	if( !m_pBase || ! m_pHttp)
	{
		LOG_ERROR("http event create failed!");
		return false;
	}
	//注册对应url的Handler
	RegistUrlHandler(m_pHttp);

	struct evhttp_bound_socket *handle = evhttp_bind_socket_with_handle(m_pHttp, m_listenAddr.c_str(), m_listenPort); 

	event_base_dispatch(m_pBase);

	evhttp_free(m_pHttp);
	event_base_free(m_pBase);
	
	return true;
}

HttpMgr::HttpMgr() : m_pImpl(NULL)
{}

HttpMgr::~HttpMgr()
{
	delete m_pImpl;
}

bool HttpMgr::Init(const string& strAddr, uint16_t port)
{
	m_pImpl = new Impl();
	
	return m_pImpl->Init(strAddr, port);
}

bool HttpMgr::StartService()
{
	if(!m_pImpl)
	{
		LOG_DEBUG("m_pImpl is null");
	}
	return m_pImpl->StartThread();
}

bool HttpMgr::StopService()
{
	if(!m_pImpl)
	{
		LOG_DEBUG("m_pImpl is null");
	}
	return m_pImpl->StopThread();
}

void HttpMgr::Impl::RegistUrlHandler(struct evhttp* pEvhttp)
{
	//evhttp_set_cb(pEvhttp, "/", Cb_Base, NULL);
	evhttp_set_gencb(pEvhttp, Cb_Base, NULL);
	UriHandlerMgr::Instance().Regist("/", Cb_Base);
}

void HttpMgr::Impl::Cb_Base(struct evhttp_request *request, void *arg)
{
	LOG_DEBUG(__FUNCTION__);
	struct evbuffer* pBuf = evbuffer_new();

	string strEcho = "welcome to fuzi's c++ web server!";
	strEcho = strEcho + " your uri is :" + string(request->uri);
	evbuffer_add(pBuf, strEcho.c_str(), strEcho.size());

	evhttp_send_reply(request, 200, "no", pBuf);
	evbuffer_free(pBuf);
}
