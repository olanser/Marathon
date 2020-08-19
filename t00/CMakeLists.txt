project(simpleSort)

cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

include_directories(src)

add_executable(simpleSort ${SOURCE_EXE})
