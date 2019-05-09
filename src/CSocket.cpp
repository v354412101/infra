#include "CSocket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

namespace Infra {
    CSocket::CSocket()
        : socket_fd_(-1) {
    }

    CSocket::~CSocket() {
    }

    bool CSocket::create() {
        socket_fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd_ < 0) {
            return false;
        }
        return true;
    }

    bool CSocket::connect(const char* ip_addr, int port) {
        struct sockaddr_in t_sockaddr;
        memset(&t_sockaddr, 0, sizeof(struct sockaddr_in));
        t_sockaddr.sin_family = AF_INET;
        t_sockaddr.sin_port = htons(port);
        inet_pton(AF_INET, ip_addr, &t_sockaddr.sin_addr);

        int ret = ::connect(socket_fd_, (struct sockaddr*)&t_sockaddr, sizeof(struct sockaddr));
        if (ret < 0) {
            return false;
        }

        return true;
    }

    ssize_t CSocket::send(const std::string &msg) {
        return ::send(socket_fd_, msg.c_str(), msg.length(), 0);
    }

    bool CSocket::bind(int port) {

        struct sockaddr_in t_sockaddr;
        memset(&t_sockaddr, 0, sizeof(t_sockaddr));
        t_sockaddr.sin_family = AF_INET;
        t_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        t_sockaddr.sin_port = htons(port);

        int ret = ::bind(socket_fd_,(struct sockaddr *) &t_sockaddr,sizeof(t_sockaddr));
        if (ret < 0) {
            fprintf(stderr, "bind socket error %s errno: %d\n", strerror(errno), errno);
        }

        return false;
    }

    bool CSocket::listen(int backlog) {
        int ret = ::listen(socket_fd_, backlog);
        if (ret < 0) {
            fprintf(stderr, "listen error %s errno: %d\n", strerror(errno), errno);
        }
        return false;
    }

    int CSocket::accept() {
        return ::accept(socket_fd_, (struct sockaddr*)NULL, NULL);
    }

    ssize_t CSocket::recv(void *buf, size_t nbyte) {
        return ::recv(socket_fd_, buf, nbyte, 0);
    }

    int CSocket::close() {
        ::close(socket_fd_);
        socket_fd_ = -1;
        return 0;
    }
}
