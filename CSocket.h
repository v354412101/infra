#pragma once

#include <monetary.h>

#include <string>

namespace Infra {
    class CSocket {
    public:
        CSocket();
        ~CSocket();

        bool create();
        bool connect(const char* ip_addr, int port);
        ssize_t send(const std::string &msg);
        ssize_t recv(void *buf, size_t nbyte);
        bool bind(int port);
        bool listen(int backlog);
        int accept();
        int close();

    private:
        int socket_fd_;
    };
}
