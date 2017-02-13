cmake_minimum_required(VERSION 2.8.7)
project(tram)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic")

file(GLOB SOURCES ./*.hpp ./*.cpp)
add_library(tram ${SOURCES})

file(GLOB TEST_SOURCES tests/*.hpp tests/*.cpp)
add_executable(tram-tests ${TEST_SOURCES})
target_link_libraries(tram-tests gtest gtest_main pthread tram)
