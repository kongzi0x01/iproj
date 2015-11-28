#ifndef EPOLL_HANDLER_H
#define EPOLL_HANDLER_H

#include <sys/epoll.h>

class EpollHandler
{
public:
	virtual int Handle(int event) = 0;
};

#endif
