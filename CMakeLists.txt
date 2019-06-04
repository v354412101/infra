cmake_minimum_required(VERSION 3.10)
project(Infra CXX)

set(CMAKE_CXX_STANDARD 11)

#include_directories(${PROJECT_SOURCE_DIR}/3rdparty/jsoncpp/include)
#link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/jsoncpp/lib/libjsoncpp.a)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_INFRA src/CFile.cpp)

set(SRC_INFRA_NET
        src/Net/BasicSocket.cpp
        src/Net/TCPSocket.cpp
        src/Net/UDPSocket.cpp)

add_library(Infra STATIC ${SRC_INFRA} ${SRC_INFRA_NET})

install(TARGETS Infra Infra LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include/Infra)