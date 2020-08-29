#pragma once

#include <iostream>
#include <fstream>
#include <forward_list>
#include <string>

struct AlgoV1 {
    AlgoV1() {
        size = 0;
        isRich = false;
        isLengths = true;
        isVel = false;
        sizeDontHaveMel = 0;
    }
    int size;
    bool isRich;
    bool isLengths;
    bool isVel;
    int sizeDontHaveMel;
};

void writeToAlgoV1(std::forward_list<std::string>& listName,
                   AlgoV1& stractAlgoV1);
