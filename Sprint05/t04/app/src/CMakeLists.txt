project(src)

set(SOURCE_EXE Axe.cpp ImperialSoldier.cpp StormcloakSoldier.cpp Sword.cpp Weapon.cpp Soldier.cpp)

add_library(src STATIC ${SOURCE_EXE})