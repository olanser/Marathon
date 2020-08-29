#include "itemInventory.h"

int main() {
    std::vector<std::string> inventory;

    while(1) {
        std::cout << "Enter command:> ";
        std::string comand;
        std::getline(std::cin, comand);
        if (comand == "exit") {
            std::cout << "Bye." << std::endl;
            return 0;
        }
        checkComand(inventory, comand);
    }
    return 0;
}