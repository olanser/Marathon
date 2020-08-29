project(src)

set(SOURCE_EXE tesLibrary.cpp checkArgument.cpp openFile.cpp printError.cpp)

add_library(src STATIC ${SOURCE_EXE})