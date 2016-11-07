cmake_minimum_required(VERSION 3.6)
project(cpu_RR)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cpu_RR ${SOURCE_FILES})