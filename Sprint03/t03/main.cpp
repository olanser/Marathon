#include "sumFileData.h"

#include <iostream>

int main() {
    std::string a = "1";
    std::cout << sumFileData<int>(a) <<std::endl;
    std::cout << sumFileData<double>(a) <<std::endl;

}