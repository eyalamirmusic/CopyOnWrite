cmake_minimum_required(VERSION 3.30)
project(CopyOnWrite)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

set(CMAKE_CXX_STANDARD 17)

add_library(CopyOnWrite INTERFACE)
target_include_directories(CopyOnWrite INTERFACE Include)
target_sources(CopyOnWrite INTERFACE Include/CopyOnWrite/CopyOnWrite.h)

enable_testing()

add_subdirectory(Example)
add_subdirectory(Tests)