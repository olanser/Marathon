#include "dragonborn.h"
#include <functional>

void Dragonborn::executeAction(const Actions action) {
    std::map<Actions, void (Dragonborn::*)(void) const> tableComand = {
        {Dragonborn::Actions::Shout, &Dragonborn::shoutThuum},
        {Dragonborn::Actions::Magic, &Dragonborn::attackWithMagic},
        {Dragonborn::Actions::Weapon, &Dragonborn::attackWithWeapon}
    };
    try {
        std::invoke(tableComand[action], this) ;
        // (tableComand[action]);
        // std::invoke(Dragonborn::shoutThuum);
    }
    catch(...) {
        std::cerr << "Invalid action" << std::endl;
        exit(1);
    }
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul" << std::endl;
}

void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*" << std::endl;
}

void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*" << std::endl;
}

