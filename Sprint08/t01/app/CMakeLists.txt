cmake_minimum_required(VERSION 3.18)

project(classWithInitializerList)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

add_library(src INTERFACE)

target_include_directories(src INTERFACE src/)


add_executable(classWithInitializerList ${SOURCE_EXE})

target_link_libraries(classWithInitializerList src)
