#pragma once

#include <iterator>
#include <iostream>

template <typename Container>
void outputContainer(const Container& container) {
    copy(container.begin(), container.end(), 
        std::ostream_iterator<typename Container::value_type>(std::cout,"\n"));
}
