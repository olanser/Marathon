#include "algorithmUtils.h"

#include <vector>

int main() {
    // // std::pair<int, int> test = {2, 200};
    // std::cout << IsInRange(15, 10, 20) << std::endl;
    // // std::cout << test.first << " " << test.second << std::endl;
    // std::cout << IsInRange(1, {2, 200}) << std::endl;
    // // std::cout << IsInRange(15, test) << std::endl;
    // std::vector<int> test = {1, 3, 6, 1 , 5, 6, 7};
    // RemoveAll(test, 1);
    // // RemoveAllIf(test, [](int a) {return (a > 3 ) ? true : false;});
    // for (auto& b: test) {
    //     std::cout << b << std::endl;
    // }
    std::vector<int> test = {55, 7, 234, 6756, 322};
    // std::cout << *MaxElement(test, [](int a, int b){return (a > b) ? true:false;}) << std::endl;
    // std::cout << Min(55, 7, 234, 6756, 322) << std::endl;
    std::cout << IndexOfIf(test, [](auto a) {return (a == 34) ? true:false;}) << std::endl;
}
