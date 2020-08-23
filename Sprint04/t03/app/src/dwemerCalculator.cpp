#include "dwemerCalculator.h"


bool checkArgm(int& argm, const std::string& strArgm,
               std::map<std::string, int>& valueVariable,
               std::string operand) {
    std::regex regular("[A-Za-z]+");
    std::cmatch result;
    std::regex regular2("[\\d]+");
    int check;

    if (std::regex_match(strArgm.c_str(), result, regular)) {
        if (valueVariable.count(strArgm) == 0) {
            std::cerr << "invalid " << operand << '\n';
            return false;
        }
        argm = valueVariable[strArgm];
    }
    else if (std::regex_match(strArgm.c_str(), result, regular2)) {
        std::stringstream ss(strArgm);
        ss >> argm;
        if (ss >> check) {
            std::cerr << operand << " out of range\n";
            return false;
        }
    }
    else {
        std::cerr << "invalid " << operand << '\n';
        return false;
    }
    return true;
}

void operationLine(std::string& line,
                   std::map<std::string, int>& valueVariable) {
    std::regex regular("\\s*([-+]?\\w+)\\s*([+\\/*-]{1})\\s*([-+]?\\w+)\\s*"
                       "={1}\\s*([A-Za-z]+)\\s*");
    std::cmatch result;
    int argm1;
    int argm2;
    int result;

    if (std::regex_match(line.c_str(), result, regular)) {
        if (checkArgm(argm1, result.str(1).c_str(), valueVariable, "operand1")
            && checkArgm(argm2, result.str(3).c_str(), valueVariable, "operand2")) {

        }
        else {
            return;
        }
    }
        // if ()
    //     listName.insert({result.str(1).c_str(), result.str(2).c_str()});
    //     return false;
    }

}