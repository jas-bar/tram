cmake_minimum_required(VERSION 2.8.7)
project(tram)


option(BUILD_TESTS "Builds the tests for tram" OFF)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic")

file(GLOB SOURCES ./*.hpp ./*.cpp)
add_library(tram ${SOURCES})

if(BUILD_TESTS) 
  file(GLOB TEST_SOURCES tests/*.hpp tests/*.cpp)
  add_executable(tram-tests ${TEST_SOURCES})
  target_link_libraries(tram-tests gtest gtest_main pthread tram)
endif()

# pkg-config installation
set(PKGCONFIG_DIR "/usr/lib/pkgconfig")
# get latest git commit in the working directory
execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
install(TARGETS tram DESTINATION /usr/lib)
file(GLOB HEADERS . "*.hpp")
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/tram/)
configure_file(tram.pc.in tram.pc @ONLY)
install(FILES tram.pc DESTINATION ${PKGCONFIG_DIR})
