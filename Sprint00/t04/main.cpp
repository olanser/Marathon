#include "referenceOrPointer.h"
#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    multiplyByPointer(&a,3);
    multiplyByReference(b, 3);
    std::cout << "a = " << a << " b = " << b << std::endl;
}