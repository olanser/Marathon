#include "creaneNameNewFile.h"

std::string creaneNameNewFile(const std::string& str,
                              const std::string& mod) {
    std::stringstream ss(str);

    std::string temp;
    std::string newFile;
    getline(ss, newFile, '.');
    newFile += mod;
    getline(ss, temp);
    if (temp.size() != 0)
        newFile += ".";
    newFile += temp;
    return newFile;
}
