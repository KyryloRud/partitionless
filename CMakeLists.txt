cmake_minimum_required(VERSION 3.23)

project(Partitionless VERSION 0.1.0 LANGUAGES CXX)

option(BUILD_UNIT_TESTS "Build all unit tests" OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_compile_options(-Wall -Wextra -pedantic)

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
if(BUILD_UNIT_TESTS)
find_package(GTest REQUIRED)
include(CTest)
endif()

add_subdirectory(include)
add_subdirectory(rpc)
add_subdirectory(src/lib)
add_subdirectory(src/cli)
add_subdirectory(src/daemon)
