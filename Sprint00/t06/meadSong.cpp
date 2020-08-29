#include "meadSong.h"

void printLine(std::string first, std::string second, std::string third,
               std::string fourth) {
    std::cout << first << " down and pass it around, " << second;
    std::cout << " of mead on the wall." << std::endl << std::endl;
    std::cout << third <<" of mead on the wall, " << fourth;
    std::cout << " of mead." << std::endl;
}

void printMeadSong(void) {
    std::cout << "99 bottles of mead on the wall, 99 bottles of mead.";
    std::cout << std::endl;
    for (int i = 98; i >= 2; i--) {
        printLine("Take one", std::to_string(i) + " bottles",
                  std::to_string(i) + " bottles",
                  std::to_string(i) + " bottles");
    }
    printLine("Take one", "1 bottle", "1 bottle", "1 bottle");
    printLine("Take it", "no more bottles", "No more bottles",
              "no more bottles");
    std::cout << "Go to the store and buy some more, 99 bottles of mead";
    std::cout << " on the wall." << std::endl;
}
