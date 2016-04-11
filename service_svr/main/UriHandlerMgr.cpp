#include "UriHandlerMgr.h"

UriHandlerMgr::UriHandlerMgr()
{}
UriHandlerMgr::~UriHandlerMgr()
{}

void UriHandlerMgr::Regist(string strUri, UriHandler* uriHandler)
{
	UriHandlerMap::iterator iterMap = m_UriHandlerMap.find(strUri);
	if(iterMap == m_UriHandlerMap.end())
	{
		m_UriHandlerMap[strUri] = uriHandler;
	}
}

UriHandler* UriHandlerMgr::GetUriHandler(string strUri)
{
	UriHandlerMap::iterator iterMap = m_UriHandlerMap.find(strUri);
	if(iterMap == m_UriHandlerMap.end())
	{
		return NULL;
	}
	else
	{
		return iterMap->second;
	}
}
