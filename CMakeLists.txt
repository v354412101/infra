cmake_minimum_required(VERSION 3.10)
project(test CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp CSocket.cpp CFile.cpp)