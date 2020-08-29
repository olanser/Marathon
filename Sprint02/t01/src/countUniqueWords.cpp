#include "countUniqueWords.h"

static void checkString(std::string& str,
                        std::multiset<std::string>& listName) {
    std::regex regular("([\\w\'-]+)");
    std::regex regularReplace("([^\\w\'-]+)");
    std::cmatch result;

    if (std::regex_match(str.c_str(), result, regular))
        listName.insert(str);
    else {
        str = std::regex_replace(str, regularReplace, " ");
        std::stringstream ss(str);
        std::string temp;
        while (getline(ss, temp, ' ')) {
            checkString(temp, listName);
        }
    }
}

void addNewWordToMultiset(std::ifstream& readFile,
                     std::multiset<std::string>& listName) {
    std::string str;
    while (readFile >> str) {
        checkString(str, listName);
    }
}

void writeFileCountUniqueWords(std::ofstream& writeFile,
                          std::multiset<std::string>& listName) {
    std::string world;
    for (auto &str: listName){
        if (str != world) {
            writeFile << str << ": " << listName.count(str) <<std::endl;
            world = str;
        }
        // writeFile << str << std::endl;
    }
}
