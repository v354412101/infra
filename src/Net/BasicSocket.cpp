#include "Net/BasicSocket.h"

namespace Infra {
namespace Net {
    BasicSocket::BasicSocket()
        : socket_fd_(-1) {
    }

    BasicSocket::~BasicSocket() {
    }
}
}
