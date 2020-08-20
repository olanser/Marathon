#include "sortValues.h"

#include <vector>
#include <iostream>

int main() {
    std::vector<std::string> check = {"az", "ad", "al", "t"};
    check.begin() = sortValues(check.begin(), check.end());
    for (auto& a: check)
        std::cout << a << "\n";
}