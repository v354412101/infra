cmake_minimum_required(VERSION 3.10)

project(Infra_test CXX)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)