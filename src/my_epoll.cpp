#include <stdio.h>

#include "my_epoll.h"

Epoll::Epoll()
{
	m_epoll_fd = create_epoll2(EPOLL_CLOEXEC);
	if (epollfd == -1) {
        printf("error:epoll_create\n");
	    exit(1);
	}
}

Epoll::~Epoll()
{}

int EpollWait(int timeout_ms)
{

	return 0;
}
