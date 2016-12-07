cmake_minimum_required(VERSION 3.6)
project(Huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Huffman.h)
add_executable(Huffman ${SOURCE_FILES})