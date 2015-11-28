#ifndef MY_EPOLL_H
#define My_EPOLL_H
#include <sys/epoll.h>

class Epoll
{
public:
	Epoll(int event_nums = 1024);
	~Epoll();

	int EpollWait(int timeout_ms);
	int AddReadEvent(int fd, void* data);
	int AddWriteEvent(int fd, void* data);
	int DelEvent(int fd);
	
private:
	int m_epoll_fd;
	struct epoll_event m_ev;
	struct epoll_event* m_pEvents;
	int m_iEventsNum;
};

#endif
