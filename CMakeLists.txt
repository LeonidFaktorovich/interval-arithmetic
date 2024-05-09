cmake_minimum_required(VERSION 3.21)

project(intervals)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frounding-math")

set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES ${SOURCES_DIR}/*.cpp)

file(GLOB_RECURSE HEADERS ${INCLUDES_DIR}/*.hpp)

include_directories(${INCLUDES_DIR})

add_executable(main ${SOURCES})
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(main PRIVATE ${INCLUDES_DIR})

add_subdirectory(examples/io)
add_subdirectory(examples/exponent)
add_subdirectory(examples/sinus)
