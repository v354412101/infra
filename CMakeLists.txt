cmake_minimum_required(VERSION 3.10)
project(test CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/3rdparty/jsoncpp/include)
link_libraries(${PROJECT_SOURCE_DIR}/thirdparty/jsoncpp/lib/libjsoncpp.a)

add_executable(main src/main.cpp src/CSocket.cpp src/CFile.cpp src/CCcnfig.cpp)