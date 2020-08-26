#include "draugrII.h"
#include "checkArgument.h"
#include "printError.h"


void twoArgc(char** argv, int& shoutNumber) {
    size_t pos = 0;
    double health;
    int frostResist;

    frostResist = std::stoi(argv[2], &pos);
    if (argv[2][pos] == '.') {
        health = std::stod(argv[2], &pos);
        if (argv[2][pos] != '\0')
            throw 1;
        Draugr draugr(health);
        draugr.shoutPhrase(shoutNumber);
    }
    else if (argv[2][pos] != '\0')
        throw 1;
    else {
        health = std::stod(argv[2], &pos);
        Draugr draugr(health);
        draugr.shoutPhrase(shoutNumber);
        Draugr draugr2(frostResist);
        draugr2.shoutPhrase(shoutNumber);
    }
}

void threeArgc(char** argv, int& shoutNumber) {
    size_t pos = 0;
    double health;
    int frostResist;

    health = std::stod(argv[2], &pos);
    if (argv[2][pos] != '\0')
        throw 1;
    frostResist = std::stoi(argv[3], &pos, 10);
    if (argv[3][pos] != '\0')
        throw 1;
    Draugr draugr(health, frostResist);
    draugr.shoutPhrase(shoutNumber);
}

int main(int argc, char** argv) {
    if (argc < 2 || argc > 4)
        checkArgument(argc, 2, "usage: ./draugr [shoutNumber] [health]"
                      " [frostResist]");
    size_t pos = 0;
    int shoutNumber;

    try {
        shoutNumber = std::stoi(argv[1], &pos, 10);
        if (argv[1][pos] != '\0')
            throw 1;
        if (shoutNumber > 9 || shoutNumber < 0)
            throw 1;
    }
    catch (...) {
        printError("Invalid shoutNumber");
    }
    try {
        if (argc == 2) {
            Draugr draugr;
            draugr.shoutPhrase(shoutNumber);
        }
        else if (argc == 3)
            twoArgc(argv, shoutNumber);
        else {
            threeArgc(argv, shoutNumber);
        }
    }
    catch (...) {
        printError("Error");
       
    }
    return 0;
}