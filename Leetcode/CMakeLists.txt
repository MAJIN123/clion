cmake_minimum_required(VERSION 3.6)
project(Leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Solution_1.h Solution_15.h)
add_executable(Leetcode ${SOURCE_FILES})