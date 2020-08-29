#pragma once

#include <iostream>
#include <list>
#include <unistd.h>

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};


void addNewRebbit(std::list<Rabbit>& listRabbit, int count, bool ifVampire);
