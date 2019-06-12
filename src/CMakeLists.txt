#glog
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/glog/include)
link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/glog/lib/libglog.a)

#jsoncpp
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/jsoncpp/include)
link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/jsoncpp/lib/libjsoncpp.a)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_INFRA CConfig.cpp CFile.cpp)

set(SRC_INFRA_NET
        Net/BasicSocket.cpp
        Net/TCPSocket.cpp
        Net/UDPSocket.cpp)

add_library(Infra STATIC ${SRC_INFRA} ${SRC_INFRA_NET})

target_link_libraries(Infra pthread)

install(TARGETS Infra Infra LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include/Infra)