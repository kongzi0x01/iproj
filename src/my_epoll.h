#ifndef MY_EPOLL.H
#define My_EPOLL.H

#include <sys/epoll.h>

class Epoll
{
public:
	Epoll();
	~Epoll();

	int EpollWait(int timeout_ms);
private:
	int m_epoll_fd;
	struct epoll_event m_ev;
	struct eopll_event* m_pEvents;
	int m_iEventsNum;
}

#endif
