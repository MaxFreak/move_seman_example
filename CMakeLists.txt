cmake_minimum_required(VERSION 3.3)
project(move_seman_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(move_seman_example ${SOURCE_FILES})