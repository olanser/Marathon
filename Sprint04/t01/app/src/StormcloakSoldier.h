#pragma once

#include "Axe.h"
#include <iostream>

class ImperialSoldier;
class StormcloakSoldier final {
public:
    StormcloakSoldier();
    ~StormcloakSoldier();

    void setWeapon(Axe* sword);
    void attack(ImperialSoldier& enemy);
    void consumeDamage(int amount);
    int getHealth() const;

private:
    Axe* m_weapon;
    int m_health;
};
