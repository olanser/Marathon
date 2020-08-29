#include "uniqueWords.h"

static void checkString(std::string& str, std::set<std::string>& listName) {
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

void addNewWordToSet(std::ifstream& readFile,
                     std::set<std::string>& listName) {
    std::string str;
    while (readFile >> str) {
        checkString(str, listName);
    }
}

void writeFileUniqueWords(std::ofstream& writeFile,
                          std::set<std::string>& listName) {
    for (auto &str: listName){
        writeFile << str << std::endl;
    }
}
