#include "vampireRabbits.h"


static void printRebbit(std::list<Rabbit>& listRabbit) {
    int male = 0;
    int females = 0;
    int vampire = 0;

    for (auto temp: listRabbit) {
        if (temp.isVampire)
            vampire++;
        if (temp.gender == Gender::Male)
            male++;
        else
            females++;
    }
    std::cout << "Males: " << male << std::endl;
    std::cout << "Females: " << females << std::endl;
    std::cout << "Vampires: " << vampire << std::endl;
    if (listRabbit.size() > 1000 || listRabbit.size() == 0)
        exit(0);
    sleep(1);
    std::cout << std::endl;
}

static bool checkAge(const Rabbit& temp) {
    if (temp.isVampire && temp.age > 8)
        return true;
    else if (temp.isVampire == 0 && temp.age > 3)
        return true;
    return false;
}

static void addAgeAndNewRebit(std::list<Rabbit>& listRabbit) {
    int male = 0;
    int females = 0;
    int vampire = 0;

    for (auto& temp: listRabbit) {
        if (temp.isVampire == 0) {
            if (temp.gender == Gender::Male)
                male++;
            else
                females++;
        }
        else
            vampire++;
        temp.age++;
    }
    if (male > females)
        addNewRebbit(listRabbit, females, true);
    else
        addNewRebbit(listRabbit, male, true);
    for (auto& temp: listRabbit) {
        if (vampire == 0)
            break;
        if (temp.isVampire == 0) {
            vampire--;
            temp.isVampire = 1;
        }
    }
    listRabbit.remove_if(checkAge);
}

int main() {
    std::list<Rabbit> listRabbit;
    srand(time(NULL));
    addNewRebbit(listRabbit, 10, 0);
    while (1) {
        printRebbit(listRabbit);
        addAgeAndNewRebit(listRabbit);
    }
}
