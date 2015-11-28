#include <cerrno>
#include <stdio.h>

#include "my_epoll.h"
#include "epoll_handler.h"
#include "logger_macro.h"

Epoll::Epoll(int event_nums)
{
	m_epoll_fd = epoll_create(event_nums);
	m_pEvents = new struct epoll_event[event_nums];
	m_iEventsNum = event_nums;
}

Epoll::~Epoll()
{
	delete[] m_pEvents;
	close(m_epoll_fd);
}

int Epoll::EpollWait(int timeout_ms)
{
	if (m_epoll_fd == -1) 
	{
		LOG_DEBUG( "error:epoll_create" );
		return -1;
	}
	
	int nfds = epoll_wait(m_epoll_fd, m_pEvents, m_iEventsNum, timeout_ms);
	
	if(nfds < 0)
	{
		LOG_DEBUG("epoll_wait");
		return nfds;
	}
	for ( int i=0; i<nfds; ++i)
	{
		EpollHandler* handler = (EpollHandler*)m_pEvents[i].data.ptr;
		if(NULL == handler)
		{
			return -1;
		}
		handler->Handle(m_pEvents[i].events);
	}
	return nfds;
}

int Epoll::AddReadEvent(int fd, void* data)
{
	m_ev.data.ptr = data;
	m_ev.events = EPOLLIN;
	int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, fd, &m_ev);
	if ( ret < 0 )
	{
		LOG_DEBUG("epoll_ctl add");
	}
	
	return ret;
}

int Epoll::AddWriteEvent(int fd, void* data)
{
	m_ev.data.ptr = data;
	m_ev.events = EPOLLOUT;
	int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, fd, &m_ev);
	if ( ret < 0 )
	{
		LOG_DEBUG("epoll_ctl add");
	}
	
	return ret;
}

int Epoll::DelEvent(int fd)
{
	int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, fd, &m_ev);	
	if ( ret < 0 )
	{
		LOG_DEBUG("epoll_ctl del");
	}
	return ret;
}