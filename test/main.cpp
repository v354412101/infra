#include <iostream>
#include <cstring>

#include "Net/UDPSocket.h"

//int main(int argc, char *argv[]) {
//
//    auto server = new Infra::Net::UDPSocket();
//    server->open();
//
//    server->bind(49152);
//
//    unsigned char recv_buffer[65535] = {0};
//    std::memset(recv_buffer, 0, 65535);
//
//    server->recvfrom(recv_buffer, 65535);
//
//    std::cout << recv_buffer << std::endl;
//
//    return 0;
//}


int main(int argc, char *argv[]) {

    auto client = new Infra::Net::UDPSocket();
    client->open();

    client->connect(49152);

    unsigned char recv_buffer[65535] = {0};
    std::memset(recv_buffer, 0, 65535);

    server->recvfrom(recv_buffer, 65535);

    std::cout << recv_buffer << std::endl;

    return 0;
}


