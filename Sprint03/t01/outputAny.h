#pragma once

#include <iostream>

template <class Container>
void outputAny(const Container& c) {
    for (const auto& temp: c)
        std::cout << temp << std::endl;
}
