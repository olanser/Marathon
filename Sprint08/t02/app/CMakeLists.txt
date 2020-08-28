cmake_minimum_required(VERSION 3.18)

project(universalReferenceDeterminant)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

add_library(src INTERFACE)

target_include_directories(src INTERFACE src/)


add_executable(universalReferenceDeterminant ${SOURCE_EXE})

target_link_libraries(universalReferenceDeterminant src)
