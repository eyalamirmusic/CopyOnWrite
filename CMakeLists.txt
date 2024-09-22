cmake_minimum_required(VERSION 3.30)
project(CopyOnWrite)

set(CMAKE_CXX_STANDARD 17)

add_library(CopyOnWrite INTERFACE)
target_include_directories(CopyOnWrite INTERFACE Include)
target_sources(CopyOnWrite INTERFACE Include/CopyOnWrite/CopyOnWrite.h)

add_subdirectory(Example)
