project(stdAlgoV1)

cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp src/stdAlgoV1.cpp)

include_directories(src)

add_executable(stdAlgoV1 ${SOURCE_EXE})