cmake_minimum_required(VERSION 3.21)

project(sinus)

file(GLOB_RECURSE SOURCES *.cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} intervals-arithmetic)