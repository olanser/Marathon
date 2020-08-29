#include "vampireRabbits.h"

Rabbit createRebit(bool ifVampire) {
    Rabbit newRebbit;

    newRebbit.age = 0;
    if ((rand() % 100) > 49)
        newRebbit.gender = Gender::Male;
    else
        newRebbit.gender = Gender::Female;
    if (ifVampire && (rand() % 100) == 50) {
        newRebbit.isVampire = true;
    }
    else
        newRebbit.isVampire = false;
    return newRebbit;
}

void addNewRebbit(std::list<Rabbit>& listRabbit, int count, bool ifVampire) {

    for (int i = 0; i < count; i++) {
        Rabbit newRebbit = createRebit(ifVampire);
        // if (newRebbit.isVampire) {
        //     for (auto& temp: listRabbit) {
        //         if (temp.isVampire == 0) {
        //             temp.isVampire = 1;
        //             break;
        //         }
        //     }
        // }
        listRabbit.push_back(newRebbit);
    }
}
