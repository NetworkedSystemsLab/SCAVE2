cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(scave2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pthread")

add_subdirectory(packages)
