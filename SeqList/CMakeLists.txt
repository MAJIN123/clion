cmake_minimum_required(VERSION 3.6)
project(SeqList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LinearList.h)
add_executable(SeqList ${SOURCE_FILES})