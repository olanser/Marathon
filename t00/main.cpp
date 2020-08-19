#include "simpleSort.h"

int main(int argc, char** argv) {
    if (argc != 6) {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5";
        std::cerr << std::endl;
    }
    else {
        std::array<std::string, 5> arr = {argv[1], argv[2], argv[3], argv[4],
                                          argv[5]};
        std::sort(arr.begin(), arr.end());
        for (auto i = 0; i < 5; i++) {
            std::cout << arr[i];
            if (i == 4)
                std::cout << std::endl;
            else
                std::cout << " ";
        }
    }
}
