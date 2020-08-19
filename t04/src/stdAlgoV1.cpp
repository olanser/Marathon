#include "stdAlgoV1.h"

void writeToAlgoV1(std::forward_list<std::string>& listName,
                   AlgoV1& stractAlgoV1) {
    for (auto& temp: listName) {
        stractAlgoV1.size++;
        if (!stractAlgoV1.isRich) {
            if (temp.find("rich", 0) != std::string::npos)
                stractAlgoV1.isRich = true;
        }
        if (stractAlgoV1.isLengths) {
            if (temp.size() == 15)
                stractAlgoV1.isLengths = false;
        }
        if (!stractAlgoV1.isVel) {
            if (temp.find("vel", 0) == '\0')
                stractAlgoV1.isVel = true;
        }
        if (temp.find("mel", 0) == std::string::npos)
            stractAlgoV1.sizeDontHaveMel++;
    }
}