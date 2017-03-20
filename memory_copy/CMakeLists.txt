cmake_minimum_required(VERSION 3.6)
project(memory_copy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(memory_copy ${SOURCE_FILES})