#pragma once

#include <fstream>
#include <iterator>
#include <string>

template <class T>
T sumFileData(const std::string& fileName) {
    std::ifstream ss(fileName);
    std::istream_iterator<T> intRead (ss);
    std::istream_iterator<T> EOFintRead;
    T sum = 0;
    while (intRead != EOFintRead) {
        sum += *intRead;
        intRead++;
    }
    return sum;
}
