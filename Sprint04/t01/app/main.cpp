#include <iostream>
#include <sstream>
#include "ImperialSoldier.h"

int getDmg(std::string arg) {
    std::stringstream ss(arg);

    int dmg;
    std::string check;
    if (!((ss >> dmg) && !(ss >> check)) || !((dmg > 9) && (dmg < 21))) {
        std::cerr << "Damage has to be in a range of 10-20 points";
        std::cerr << std::endl;
        exit(1);
    }
    return dmg;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]";
        std::cerr << std::endl;
        exit(1);
    }
    Sword sword(getDmg(argv[1]));
    Axe axe(getDmg(argv[2]));
    ImperialSoldier imperial;
    StormcloakSoldier stormcloak;
    imperial.setWeapon(&sword);
    stormcloak.setWeapon(&axe);
    while (imperial.getHealth() && stormcloak.getHealth()) {
        imperial.attack(stormcloak);
        stormcloak.attack(imperial);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    }
    if (imperial.getHealth())
        std::cout << "Imperial has won!" << std::endl;
    else
        std::cout << "Stormcloak has won!" << std::endl;
    return 0;
}
