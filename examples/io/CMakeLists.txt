cmake_minimum_required(VERSION 3.21)

project(io)

file(GLOB_RECURSE SOURCES *.cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(io ${SOURCES})

target_link_libraries(io intervals)