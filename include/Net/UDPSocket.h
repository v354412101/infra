#pragma once

#include <monetary.h>

#include "BasicSocket.h"

#include <string>

namespace Infra {
namespace Net {
    class UDPSocket : public BasicSocket {
    public:
        UDPSocket();
        ~UDPSocket();
        int open() override;
        int connect(const char *ip_addr, int port) const;
        int bind(unsigned int port) const;
        ssize_t sendto(const void *buf, size_t len, const std::string&& ip_addr = "", unsigned int port = 0) const;
        ssize_t recvfrom(void *buf, size_t nbyte, std::string&& ip_addr = "", unsigned int port = 0) const;
        int close() override;
    };
}
}

