#include "outputAny.h"

// // #include <iostream>
#include <set>

int main() {
    std::set<int> test{2,3,4,5,67,8,56};
    for (auto a: test) {
        std::cout << a << std::endl;
    }
    std::string a = "adwawdwda";
    outputAny(test);
}
