#include "src/draugrIII.h"
#include "checkArgument.h"
#include "printError.h"
#include <regex>


void threeArgc(char** argv, int& shoutNumber, const std::string name1,
               const std::string name2) {
    size_t pos = 0;
    double health;

    health = std::stod(argv[3], &pos);
    if (argv[3][pos] != '\0')
        throw 1;
    else {
        Draugr draugr(health);
        draugr.setName(std::move(name1));
        draugr.shoutPhrase(shoutNumber);
        Draugr draugr2(draugr);
        draugr2.setName(std::move(name2));
        draugr2.shoutPhrase(shoutNumber);
    }
}

void fourArgc(char** argv, int& shoutNumber, const std::string name1,
              const std::string name2) {
    size_t pos = 0;
    double health;
    int frostResist;

    health = std::stod(argv[3], &pos);
    if (argv[3][pos] != '\0')
        throw 1;
    frostResist = std::stoi(argv[4], &pos, 10);
    if (argv[4][pos] != '\0')
        throw 1;
    Draugr draugr(health, frostResist);
    draugr.setName(std::move(name1));
    draugr.shoutPhrase(shoutNumber);
    Draugr draugr2(std::move(draugr));
    draugr2.setName(std::move(name2));
    draugr2.shoutPhrase(shoutNumber);
    
    // size_t pos = 0;
    // double health;
    // int frostResist;

    // health = std::stod(argv[2], &pos);
    // if (argv[2][pos] != '\0')
    //     throw 1;
    // frostResist = std::stoi(argv[3], &pos, 10);
    // if (argv[3][pos] != '\0')
    //     throw 1;
    // Draugr draugr(health, frostResist);
    // draugr.shoutPhrase(shoutNumber);
    // Draugr draugr2(draugr);
    // draugr2.shoutPhrase(shoutNumber);
}

int main(int argc, char** argv) {
    if (argc < 4 || argc > 5)
        checkArgument(argc, 2, "usage: ./draugr [shoutNumber] [name1,name2]"
                      " [health] [frostResist]");
    size_t pos = 0;
    int shoutNumber;

    try {
        shoutNumber = std::stoi(argv[1], &pos, 10);
        if (argv[1][pos] != '\0')
            throw 1;
    }
    catch (...) {
        printError("Invalid shoutNumber");
    }
    try {
        std::regex regular("(\\w+),(\\w+)");
        std::cmatch result;
        if (!(std::regex_match(argv[2], result, regular))) {
            printError("Invalid names");
        }
        if (argc == 4) {
            threeArgc(argv, shoutNumber, result.str(1).c_str(),
                      result.str(2).c_str());
        }
        else 
            fourArgc(argv, shoutNumber, result.str(1).c_str(),
                     result.str(2).c_str());
    }
    catch (...) {
        printError("Error");
    }
    return 0;
}