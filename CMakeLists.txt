cmake_minimum_required(VERSION 3.22)

project(channel_c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/dokastho/code/pthread_sandbox/bin")

set(CMAKE_C_COMPILER, "clang")

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -std=c99 -Wconversion -Wall -Werror -Wextra -pedantic")
set(THREADS_PREFER_PTHREAD_FLAG ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -DDEBUG")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Fast")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ofast")
endif()

file(GLOB SOURCES "src/*.c")
list(FILTER SOURCES EXCLUDE REGEX "src/test_.*\\.c")

find_package(Threads REQUIRED)

file(GLOB TEST_SOURCES "src/test_*.c")
add_library(channel_lib SHARED ${SOURCES})
target_link_libraries(channel_lib PRIVATE Threads::Threads)
target_link_libraries(channel_lib ${LLVM_LIBRARIES})

if(CMAKE_BUILD_TYPE STREQUAL "Test")
    add_executable(chan_tests ${TEST_SOURCES})
endif()
