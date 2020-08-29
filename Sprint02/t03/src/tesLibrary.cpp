#include "tesLibrary.h"

bool checkLine(std::multimap<std::string, std::string>& listName, std::string& line) {
    std::regex regular("\\s*\"([^\"]*)\"\\s*:\\s*\"([^\"]*)\"\\s*");
    std::cmatch result;

    if (std::regex_match(line.c_str(), result, regular)) {
        listName.insert({result.str(1).c_str(), result.str(2).c_str()});
        return false;
    }
    return true;
}


void addNewWordToMultimap(std::ifstream& readFile,
                          std::multimap<std::string, std::string>& listName) {
    std::string line;

    int i = 0;
    while (getline(readFile, line)) {
        i++;
        if (!line.empty()) {
            if (checkLine(listName, line)) {
                std::string error = "Line " + std::to_string(i) + " is invalid";
                printError(error);
            }
        }
    }
    if (i == 0)
        printError("error");
}

void writeBookToAutor(std::multimap<std::string, std::string>& listName) {
    std::string nameAutor;
    int size;

    for (auto& map: listName) {
        if (map.first != nameAutor) {
            std::cout << map.first << ":\n";
            nameAutor = map.first;
            size = 1;
            std::cout << " " << size << ": "<< map.second << std::endl;
        }
        else {
            size++;
            std::cout << " " << size << ": "<< map.second << std::endl;
        }
    }
}
