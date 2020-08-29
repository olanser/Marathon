#include "stdAlgoV1.h"

void printBool(bool check) {
    if (check)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]" << std::endl;
        return 1;
    }
    std::ifstream myFile(argv[1]);
    if (!myFile.is_open()) {
        std::cerr << "error" << std::endl;
        return 1;
    }
    std::string std;
    std::forward_list<std::string> listName; 
    while(std::getline(myFile, std))
        listName.push_front(std);
    AlgoV1 stractAlgoV1;
    writeToAlgoV1(listName, stractAlgoV1);
    if (stractAlgoV1.size == 0) {
        std::cerr << "error" << std::endl;
        return 1;
    }
    std::cout << "size: " << stractAlgoV1.size << std::endl;
    std::cout << "contains 'rich': ";
    printBool(stractAlgoV1.isRich);
    std::cout << "none of lengths is 15: ";
    printBool(stractAlgoV1.isLengths);
    std::cout << "all end with 'vel': ";
    printBool(stractAlgoV1.isVel);
    std::cout << "not contains 'mel': " << stractAlgoV1.sizeDontHaveMel;
    std::cout << std::endl;
    return 0;
}
