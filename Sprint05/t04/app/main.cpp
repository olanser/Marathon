#include <iostream>
#include <sstream>
#include "ImperialSoldier.h"
#include "StormcloakSoldier.h"

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
    std::cout << "\n***The battle has begun!***\n\n";
    while (imperial.getHealth() > 0 && stormcloak.getHealth() > 0) {
        stormcloak.attack(imperial);
        imperial.attack(stormcloak);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    }
    if (imperial.getHealth() > 0)
        std::cout << "Imperial has won!\n" << std::endl;
    else
        std::cout << "Stormcloak has won!\n" << std::endl;
    return 0;
}
