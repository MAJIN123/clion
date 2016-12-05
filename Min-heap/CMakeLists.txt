cmake_minimum_required(VERSION 3.6)
project(Min_heap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Min_heap ${SOURCE_FILES})