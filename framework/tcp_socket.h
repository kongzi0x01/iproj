
#ifndef _NETKIT_TCP_SOCKET_H
#define _NETKIT_TCP_SOCKET_H

extern "C" {
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
}

//#include <string>
//#include <sstream>

///
/// \file TcpSocket.h
/// \brief Class that hides the internals of doing socket I/O.
///


///
/// \class TcpSocket
/// \brief TCP sockets used in KFS are (1) non-blocking for I/O and (2) have
/// large send/receive buffers.
/// 
class TcpSocket {
public:
    TcpSocket() {
        mSockFd = -1;
    }
    /// Wrap the passed in file descriptor in a TcpSocket
    /// @param[in] fd file descriptor corresponding to a TCP socket.
    TcpSocket(int fd) {
        mSockFd = fd;
    }

    ~TcpSocket();

    /// Setup a TCP socket that listens for connections
    /// @param port Port on which to listen for incoming connections
    int Listen(const char* pszIP, int port);

    /// Accept connection on a socket.
    /// @retval A TcpSocket pointer that contains the accepted
    /// connection.  It is the caller's responsibility to free the
    /// pointer returned by this method.
    ///
    TcpSocket* Accept();
    int Accept(TcpSocket& sock);

    /// Connect to the remote address.  If non-blocking connect is
    /// set, the socket is first marked non-blocking and then we do
    /// the connect call.  Then, you use select() to check for connect() completion
    /// @retval 0 on success; -1 on failure; -EINPROGRESS if we do a
    /// nonblockingConnect and connect returned that error code
    int Connect(const struct sockaddr_in *remoteAddr, bool nonblockingConnect = false); 
    int Connect(const char* pszHost, int iPort, bool nonblockingConnect = false);

    /// Do block-IO's, where # of bytes to be send/recd is the length
    /// of the buffer.
    /// @retval Returns # of bytes sent or -1 if there was an error.
    int DoSynchSend(const char *buf, int bufLen);

    /// For recv/peek, specify a timeout within which data should be received.
    int DoSynchRecv(char *buf, int bufLen, struct timeval &timeout);
    int DoSynchPeek(char *buf, int bufLen, struct timeval &timeout);

    /// Discard a bunch of bytes that are coming down the pike.
    int DoSynchDiscard(int len, struct timeval &timeout);

    /// Peek to see if any data is available.  This call will not
    /// remove the data from the underlying socket buffers.
    /// @retval Returns # of bytes copied in or -1 if there was an error.
    int Peek(char *buf, int bufLen);

    /// Get the file descriptor associated with this socket.
    inline int GetFd() { return mSockFd; };
    inline void SetFd(int iFd) { mSockFd=iFd; };

    /// Return true if socket is good for read/write. false otherwise.
    bool IsGood();

    int GetPeerName(struct sockaddr *peerAddr);

    /// Sends at-most the specified # of bytes.  
    /// @retval Returns the result of calling send().
    int Send(const char *buf, int bufLen);

    /// Receives at-most the specified # of bytes.
    /// @retval Returns the result of calling recv().
    int Recv(char *buf, int bufLen);

    /// Close the TCP socket.
    void Close();

private:
    int mSockFd;

    void SetupSocket();
};

//typedef boost::shared_ptr<TcpSocket> TcpSocketPtr;


#endif // _LIBIO_TCP_SOCKET_H
