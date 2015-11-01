#include "tcp_socket.h"
#include <cerrno>
#include <poll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <assert.h>

TcpSocket::~TcpSocket()
{
    Close();
}

int TcpSocket::Listen(const char* pszIP, int port)
{
    struct sockaddr_in	ourAddr;
    int reuseAddr = 1;

    mSockFd = socket(PF_INET, SOCK_STREAM, 0);
    if (mSockFd == -1) {
        perror("Socket: ");
        return -1;
    }

    memset(&ourAddr, 0, sizeof(struct sockaddr_in));
    ourAddr.sin_family = AF_INET;
	if (pszIP == NULL )
		ourAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	else
		ourAddr.sin_addr.s_addr = htonl(inet_addr(pszIP));;
    ourAddr.sin_port = htons(port);

    /* 
     * A piece of magic here: Before we bind the fd to a port, setup
     * the fd to reuse the address. If we move this line to after the
     * bind call, then things don't work out.  That is, we bind the fd
     * to a port; we panic; on restart, bind will fail with the address
     * in use (i.e., need to wait 2MSL for TCP's time-wait).  By tagging
     * the fd to reuse an address, everything is happy.
     */
    if (setsockopt(mSockFd, SOL_SOCKET, SO_REUSEADDR, 
                   (char *) &reuseAddr, sizeof(reuseAddr)) < 0) {
        perror("Setsockopt: ");
    }

    if (bind(mSockFd, (struct sockaddr *) &ourAddr, sizeof(ourAddr)) < 0) {
        perror("Bind: ");
        close(mSockFd);
        mSockFd = -1;
        return -1;
    }
    
    if (listen(mSockFd, 14) < 0) {
        perror("listen: ");
    }

    return 0;
    
}

TcpSocket* TcpSocket::Accept()
{
    int fd;
    struct sockaddr_in	cliAddr;    
    TcpSocket *accSock = NULL;
    socklen_t cliAddrLen = sizeof(cliAddr);

    if ((fd = accept(mSockFd, (struct sockaddr *) &cliAddr, &cliAddrLen)) < 0) {
        perror("Accept: ");
        return NULL;
    }
    accSock = new TcpSocket(fd);

    accSock->SetupSocket();

    return accSock;
}

int TcpSocket::Accept(TcpSocket& sock)
{
    int fd;
    struct sockaddr_in	cliAddr;    
    socklen_t cliAddrLen = sizeof(cliAddr);

    if ((fd = accept(mSockFd, (struct sockaddr *) &cliAddr, &cliAddrLen)) < 0) {
        perror("Accept: ");
        return -1;
    }

    sock.SetFd(fd);
    sock.SetupSocket();
    return 0;
}


int TcpSocket::Connect(const struct sockaddr_in *remoteAddr, bool nonblockingConnect)
{
    int res = 0;

    Close();

    mSockFd = socket(PF_INET, SOCK_STREAM, 0);
    if (mSockFd == -1) {
        return -1;
    }

    if (nonblockingConnect) {
        // when we do a non-blocking connect, we mark the socket
        // non-blocking; then call connect and it wil return
        // EINPROGRESS; the fd is added to the select loop to check
        // for completion
        fcntl(mSockFd, F_SETFL, O_NONBLOCK);
    }

    res = connect(mSockFd, (struct sockaddr *) remoteAddr, sizeof(struct sockaddr_in));
    if ((res < 0) && (errno != EINPROGRESS)) {
        perror("Connect: ");
        close(mSockFd);
        mSockFd = -1;
        return -1;
    }

    if (nonblockingConnect)
        res = -errno;

    //SetupSocket();

    return res;
}

int TcpSocket::Connect(const char* pszHost, int iPort, bool nonblockingConnect)
{
    struct hostent *hostInfo;
    struct sockaddr_in remoteAddr;

    remoteAddr.sin_addr.s_addr = inet_addr(pszHost);
    if (remoteAddr.sin_addr.s_addr == (in_addr_t) -1) {
        // do the conversion if we weren't handed an IP address

        hostInfo = gethostbyname(pszHost);

        if (hostInfo == NULL) {
            perror("TcpSocket::Connect gethostbyname");
            return -1;
        }

        memcpy(&remoteAddr.sin_addr.s_addr, hostInfo->h_addr, sizeof(struct in_addr));
    }
    remoteAddr.sin_port = htons(iPort);
    remoteAddr.sin_family = AF_INET;

    return Connect(&remoteAddr, nonblockingConnect);
}

void TcpSocket::SetupSocket()
{
#if defined(__sun__)
    int bufSize = 512 * 1024;
#else
    int bufSize = 65536;
#endif
    int flag = 1;

    // get big send/recv buffers and setup the socket for non-blocking I/O
    if (setsockopt(mSockFd, SOL_SOCKET, SO_SNDBUF, (char *) &bufSize, sizeof(bufSize)) < 0) {
        perror("Setsockopt: ");
    }
    if (setsockopt(mSockFd, SOL_SOCKET, SO_RCVBUF, (char *) &bufSize, sizeof(bufSize)) < 0) {
        perror("Setsockopt: ");
    }
    // enable keep alive so we can socket errors due to detect network partitions
    if (setsockopt(mSockFd, SOL_SOCKET, SO_KEEPALIVE, (char *) &flag, sizeof(flag)) < 0) {
        perror("Disabling NAGLE: ");
    }

    fcntl(mSockFd, F_SETFL, O_NONBLOCK);
    // turn off NAGLE
    if (setsockopt(mSockFd, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(flag)) < 0) {
        perror("Disabling NAGLE: ");
    }
}

int TcpSocket::GetPeerName(struct sockaddr *peerAddr)
{
    socklen_t peerLen;

    if (getpeername(mSockFd, peerAddr, &peerLen) < 0) {
        perror("getpeername: ");
        return -1;
    }
    return 0;
}

int TcpSocket::Send(const char *buf, int bufLen)
{
    return send(mSockFd, buf, bufLen, MSG_DONTWAIT);
}

int TcpSocket::Recv(char *buf, int bufLen)
{
	return recv(mSockFd, buf, bufLen, MSG_DONTWAIT);
}

int TcpSocket::Peek(char *buf, int bufLen)
{
	return recv(mSockFd, buf, bufLen, MSG_PEEK);
}

bool TcpSocket::IsGood()
{
    if (mSockFd < 0)
        return false;

#if 0
    char c;
    
    // the socket could've been closed by the system because the peer
    // died.  so, tell if the socket is good, peek to see if any data
    // can be read; read returns 0 if the socket has been
    // closed. otherwise, will get -1 with errno=EAGAIN.
    
    if (Peek(&c, 1) == 0)
        return false;
#endif
    return true;
}


void TcpSocket::Close()
{
    if (mSockFd < 0) {
        return;
    }
    close(mSockFd);
    mSockFd = -1;
}

int TcpSocket::DoSynchSend(const char *buf, int bufLen)
{
    int numSent = 0;
    int res = 0, nfds;
    fd_set fds;
    struct timeval timeout;

    while (numSent < bufLen) {
        if (mSockFd < 0)
            break;
        if (res < 0) {
            FD_ZERO(&fds);
            FD_SET(mSockFd, &fds);
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            nfds = select(mSockFd + 1, NULL, &fds, &fds, &timeout);
            if (nfds == 0)
                continue;
        }

        res = Send(buf + numSent, bufLen - numSent);
        if (res == 0)
            return 0;
        if ((res < 0) && 
            ((errno == EAGAIN) || (errno == EWOULDBLOCK) || (errno == EINTR)))
            continue;
        if (res < 0)
            break;
        numSent += res;
    }
    return numSent;
}

// 
// Receive data within a certain amount of time.  If the server is too slow in responding, bail
//
int TcpSocket::DoSynchRecv(char *buf, int bufLen, struct timeval &timeout)
{
    int numRecd = 0;
    int res = 0, nfds;
    struct pollfd pfd;

    while (numRecd < bufLen) {
        if (mSockFd < 0)
            break;

        if (res < 0) {
            pfd.fd = mSockFd;
            pfd.events = POLLIN;
            pfd.revents = 0;
            nfds = poll(&pfd, 1, timeout.tv_sec * 1000);
            // get a 0 when timeout expires
            if (nfds == 0) {
                //"Timeout in synch recv"
                return numRecd > 0 ? numRecd : -ETIMEDOUT;
            }
        }

        res = Recv(buf + numRecd, bufLen - numRecd);
        if (res == 0)
            return 0;
        if ((res < 0) && 
            ((errno == EAGAIN) || (errno == EWOULDBLOCK) || (errno == EINTR)))
            continue;
        if (res < 0)
            break;
        numRecd += res;
    }

    return numRecd;
}


// 
// Receive data within a certain amount of time and discard them.  If
// the server is too slow in responding, bail
//
int TcpSocket::DoSynchDiscard(int nbytes, struct timeval &timeout)
{
    int numRecd = 0, ntodo, res;
    const int bufSize = 4096;
    char buf[bufSize];

    while (numRecd < nbytes) {
        ntodo = nbytes - numRecd < bufSize ? nbytes - numRecd : bufSize;
        res = DoSynchRecv(buf, ntodo, timeout);
        if (res == -ETIMEDOUT)
            return numRecd;
        assert(numRecd >= 0);
        if (numRecd < 0)
            break;
        numRecd += res;
    }
    return numRecd;
}

// 
// Peek data within a certain amount of time.  If the server is too slow in responding, bail
//
int TcpSocket::DoSynchPeek(char *buf, int bufLen, struct timeval &timeout)
{
    int numRecd = 0;
    int res, nfds;
    struct pollfd pfd;

    while (1) {
        pfd.fd = mSockFd;
        pfd.events = POLLIN;
        pfd.revents = 0;
        nfds = poll(&pfd, 1, timeout.tv_sec * 1000);
        // get a 0 when timeout expires
        if (nfds == 0) {
            return -ETIMEDOUT;
        }

        res = Peek(buf + numRecd, bufLen - numRecd);
        if (res == 0)
            return 0;
        if ((res < 0) && (errno == EAGAIN))
            continue;
        if (res < 0)
            break;
        numRecd += res;
        if (numRecd > 0)
            break;
    }
    return numRecd;
}
