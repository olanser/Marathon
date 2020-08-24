cmake_minimum_required(VERSION 3.18)

project(imperialVsStormcloak)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

include_directories(src)

add_executable(imperialVsStormcloak ${SOURCE_EXE})

add_subdirectory(src)				# Добавление подпроекта, указывается имя дирректории

target_link_libraries(imperialVsStormcloak src)