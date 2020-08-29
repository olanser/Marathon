project(src)

set(SOURCE_EXE bookSaver.cpp command.cpp openFile.cpp)

add_library(src STATIC ${SOURCE_EXE})