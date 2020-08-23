project(src)

set(SOURCE_EXE Axe.cpp ImperialSoldier.cpp StormcloakSoldier.cpp Sword.cpp)

add_library(src STATIC ${SOURCE_EXE})