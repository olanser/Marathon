#include "isPalindrome.h"

#include <vector>
#include <iostream>

int main() {
    std::vector<int> test = { 1, 2, 3, 3, 2, 1};
    std::cout << isPalindrome(test.begin(), test.end()) << std::endl;
}