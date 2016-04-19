cmake_minimum_required(VERSION 3.5)
project(stl_matrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Tensor.h)
add_executable(stl_matrix ${SOURCE_FILES})