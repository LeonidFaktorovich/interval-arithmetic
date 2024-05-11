cmake_minimum_required(VERSION 3.0)

project(intervals-arithmetic)

option(BENCHMARK "Build the project with benchmarking" OFF)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES ${SOURCES_DIR}/*.cpp)

file(GLOB_RECURSE HEADERS ${INCLUDES_DIR}/*.hpp)

include_directories(${INCLUDES_DIR})

add_executable(main ${SOURCES})
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
if(WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE /fp:strict)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -frounding-math)
endif()

target_include_directories(main PRIVATE ${INCLUDES_DIR})

if (BENCHMARK)
    message(STATUS "Benchmarking is enabled")
    find_package(benchmark REQUIRED)
    file(GLOB_RECURSE BENCHMARKS_SOURCES "benchmarks/*.cpp")
    add_executable(intervals_benchmarks ${BENCHMARKS_SOURCES})
    target_link_libraries(intervals_benchmarks PUBLIC ${PROJECT_NAME} benchmark::benchmark)
endif()

add_subdirectory(examples/io)
add_subdirectory(examples/exponent)
add_subdirectory(examples/sinus)
