#include "itemInventory.h"


static void printCommandHelp(void) {
    std::cout << "Available commands:" << std::endl;
    std::cout << "1. insert <itemType>" << std::endl;
    std::cout << "2. remove <itemType>" << std::endl;
    std::cout << "3. show inventory" << std::endl;
    std::cout << "4. help" << std::endl;
    std::cout << "5. exit" << std::endl;
}


static void printCommandShow(std::vector<std::string>& inventory) {
    std::cout << "Inventory { ";
    for (auto &item: inventory)
        std::cout << item << " ";
    for (int i = inventory.size(); i < 12; i++)
        std::cout << "- ";
    std::cout << "}" << std::endl;
}

static void printCommandInsert(std::vector<std::string>& inventory,
                               std::string& item) {
    if (inventory.size() == 12)
        std::cerr << "Inventory is full." << std::endl;
    else {
        inventory.push_back(item);
        std::cout << item << " was inserted." << std::endl;
    }
}

static void printCommandRemove(std::vector<std::string>& inventory,
                               std::string& deleteItem) {
    int i = 0;
    for (auto &item: inventory) {
        if (item == deleteItem) {
            inventory.erase(inventory.begin() + i);
            std::cout << deleteItem << " was removed." << std::endl;
            return;
        }
        i++;
    }
    std::cerr << "Invalid item." << std::endl;
}

void checkComand(std::vector<std::string>& inventory, std::string command) {
    if (command == "help")
        printCommandHelp();
    else if (command == "show")
        printCommandShow(inventory);
    else {
        std::stringstream ss;
        ss << command;
        std::string comm;
        std::string item;
        ss >> comm;
        if (ss.eof() != 0 || (comm != "insert" && comm != "remove")) {
            std::cerr << "Invalid command." << std::endl;
            return;
        }
        ss >> item;
        if (ss.eof() == 0) {
            std::cerr << "Invalid command." << std::endl;
            return;
        }
        if (!(item == "w" || item == "a" || item == "f" || item == "p")) {
            std::cerr << "Invalid item." << std::endl;
            return;
        }
        if (comm == "insert")
            printCommandInsert(inventory, item);
        else
            printCommandRemove(inventory, item);
    }
}