#include "command.h"

void commandQuit(void) {
    std::cout << "Bye" << std::endl;
    exit(0);
}

void commandList(const std::map<std::string, std::string>& listBook) {
    for (const auto& str: listBook) {
        std::cout << str.first << std::endl;
    }
}

void commandAdd(std::map<std::string, std::string>& listBook,
                const std::string& book) {
    std::string path = "./library/" + book;

    std::ifstream ifs;
    std::string readBook;
    std::string check;
    if (openFileRead(ifs, path)) {
        getline(ifs, readBook, '\0');
        if (readBook.size() == 0)
            std::cout << "invalid book" << std::endl;
        else {
            listBook[book] = readBook;
            std::cout << book << " added" << std::endl;
        }
    }
    else {
        std::cout << "invalid book" << std::endl;
    }
}

void commandDelete(std::map<std::string, std::string>& listBook,
                const std::string& book) {
    if (listBook.count(book) == 1) {
        listBook.erase(book);
        std::cout << book << " deleted" << std::endl;
    }
    else {
        std::cout << "invalid book" << std::endl;
    }
}

void commandRead(std::map<std::string, std::string>& listBook,
                const std::string& book) {
    if (listBook.count(book) == 1) {
        std::cout << listBook[book] << std::endl;
    }
    else {
        std::cout << "invalid book" << std::endl;
    }
}
