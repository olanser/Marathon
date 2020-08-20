#include "sumOfArguments.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> test = {"1", "2", "3", "4"};

    std::cout << sumOfArguments(test[0], test[0], test[3], test[0],test[2], test[1],test[0],test[0]) << std::endl;
}