#include "stdAlgoV2.h"

static bool deleteCharaters(const std::string& str) {
    if (str.find("c", 0) != std::string::npos)
        return true;
    if (str.find("b", 0) != std::string::npos)
        return true;
    if (str.find("l", 0) != std::string::npos)
        return true;
    return false;
}

void chengeForvardList(std::forward_list<std::string>& listName) {
    listName.remove_if(deleteCharaters);
    std::forward_list<std::string>::iterator it = listName.begin();
    while (it != listName.end()) {
        it = std::find_if(it, listName.end(), [](const std::string &a){
                if (a.size() > 10 || a.size() < 4) 
                    return true;
                return false; 
            }
        );
        if (it != listName.end()) {
            if ((*it).size() > 10)
                *it = "Long one";
            else
                *it = "Short one";
            it++;
        }
    }
    listName.sort();
    listName.unique();
    listName.reverse();
}

std::string creaneNameNewFile(const std::string& str) {
    std::stringstream ss(str);

    std::string temp;
    std::string newFile;
    getline(ss, newFile, '.');
    newFile += "_mod";
    getline(ss, temp);
    if (temp.size() != 0)
        newFile += ".";
    newFile += temp;
    return newFile;
}

void printError(void) {
    std::cerr << "error" << std::endl;
    exit(1);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]" << std::endl;
        return 1;
    }
    std::ifstream myFile(argv[1]);
    if (!myFile.is_open());
        printError();
    std::string std;
    bool check = true;
    std::forward_list<std::string> listName; 
    while(std::getline(myFile, std)) {
        check = false;
        listName.push_front(std);
    }
    if (check)
        printError();
    std::ofstream newFile(creaneNameNewFile(argv[1]));
    if (!newFile.is_open())
        printError();
    chengeForvardList(listName);
    for (auto& temp: listName)
        newFile << temp << std::endl; 
}
