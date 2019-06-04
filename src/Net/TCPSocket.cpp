#include "Net/TCPSocket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <cstring>

namespace Infra {
namespace Net {
    TCPSocket::TCPSocket() {}

    TCPSocket::~TCPSocket() {}

    int TCPSocket::open() {
        return socket_fd_ = ::socket(AF_INET, SOCK_STREAM, 0);
    }

    int TCPSocket::connect(const char* ip_addr, int port) const {
        struct sockaddr_in t_sockaddr;
        std::memset(&t_sockaddr, 0, sizeof(t_sockaddr));

        t_sockaddr.sin_family = AF_INET;
        t_sockaddr.sin_port = htons(port);
        inet_pton(AF_INET, ip_addr, &t_sockaddr.sin_addr);

        return ::connect(socket_fd_, (struct sockaddr*)&t_sockaddr, sizeof(struct sockaddr));
    }

    ssize_t TCPSocket::send(const void *buf, size_t len) const {
        return ::send(socket_fd_, buf, len, 0);
    }

    int TCPSocket::bind(int port) const {
        struct sockaddr_in t_sockaddr;
        std::memset(&t_sockaddr, 0, sizeof(t_sockaddr));

        t_sockaddr.sin_family = AF_INET;
        t_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        t_sockaddr.sin_port = htons(port);

        return ::bind(socket_fd_, (struct sockaddr *)&t_sockaddr, sizeof(t_sockaddr));
    }

    int TCPSocket::listen(int backlog) const {
        return ::listen(socket_fd_, backlog);
    }

    int TCPSocket::accept() const {
        return ::accept(socket_fd_, (struct sockaddr*)nullptr, nullptr);
    }

    ssize_t TCPSocket::recv(void *buf, size_t nbyte) const {
        return ::recv(socket_fd_, buf, nbyte, 0);
    }

    int TCPSocket::close() {
        ::close(socket_fd_);
        socket_fd_ = -1;
        return 0;
    }
}
}
