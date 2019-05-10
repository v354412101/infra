#include <iostream>

#include "CSocket.h"
#include "CConfig.h"
#include "Singleton.h"

int main(int argc, char *argv[]) {
//    bool bRet = false;
//
//    auto *sock = new Infra::CSocket();
//
//    bRet = sock->create();
//    if (!bRet) {
//        std::cerr << "create failed!" << std::endl;
//        return 0;
//    }
//
//    bRet = sock->connect("192.168.2.41", 10004);
//    if (!bRet) {
//        std::cerr << "connect failed!" << std::endl;
//        return 0;
//    }
//
//    sock->send("hello");

    Singleton<Infra::CConfig>::Instance("/tmp/config/test.json")->init();

    return 0;
}

