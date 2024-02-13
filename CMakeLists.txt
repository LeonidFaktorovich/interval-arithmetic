cmake_minimum_required(VERSION 3.21)

project(intervals)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(main ${SOURCE_FILES})

target_include_directories(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")