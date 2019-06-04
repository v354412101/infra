#pragma once

#include <monetary.h>

namespace Infra {
namespace Net {
    class BasicSocket {
    public:
        BasicSocket();
        virtual ~BasicSocket();
        virtual int open() = 0;
        virtual int close() = 0;
    protected:
        int socket_fd_;
    };
}
}
