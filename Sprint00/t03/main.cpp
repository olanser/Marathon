#include "castSpells.h"
#include <iostream>

int main() {
    float number = 4.7f;
    int* check = new int [10];
    check[5] = 45;
    const int* test = check;

    std::cout << "number = " << typeid(number).name() << std::endl;
    std::cout << "number = " << typeid(check).name() << std::endl;
    std::cout << "number = " << typeid(test).name() << std::endl;
    int a = castFloatToInt(number);
    std::cout << "number = " << typeid(a).name() << std::endl;
    int* b = castToNonConstIntPtr(test);
    std::cout << "number = " << b[5] << typeid(b).name() << std::endl;
}