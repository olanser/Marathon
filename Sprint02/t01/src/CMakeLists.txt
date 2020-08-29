project(src)

set(SOURCE_EXE countUniqueWords.cpp checkArgument.cpp
    openFile.cpp printError.cpp creaneNameNewFile.cpp)

add_library(src STATIC ${SOURCE_EXE})