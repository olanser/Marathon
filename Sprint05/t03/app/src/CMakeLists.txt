project(src)

set(SOURCE_EXE checkArgument.cpp draugr.cpp printError.cpp)

add_library(src STATIC ${SOURCE_EXE})