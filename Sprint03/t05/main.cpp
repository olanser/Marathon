#include "squareValue.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> check = {3,5,8,9,2,5,6};

    squareValue(check);
    for (auto& a: check)
        std::cout << a << "\n";
}