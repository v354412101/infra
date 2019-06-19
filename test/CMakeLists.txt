#gtest
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/gtest/include)
link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/gtest/lib/libgtest.a)

#jsoncpp
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/jsoncpp/include)
link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/jsoncpp/lib/libjsoncpp.a)

#glog
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/glog/include)
link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/glog/lib/libglog.a)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(unit_tests
        main.cpp
        CConfig_test.cpp
        CFile_test.cpp
        )

target_link_libraries(unit_tests
        pthread
        Infra
        )

add_test(NAME unit COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)