#include "SmartPointers.h"


size_t getSize(std::string arg) {
    std::stringstream ss(arg);

    size_t dmg;
    std::string check;
    if (!((ss >> dmg) && !(ss >> check))) {
        std::cerr << "Invalid input";
        std::cerr << std::endl;
        exit(1);
    }
    return dmg;
}

void checkRange(size_t size) {
    if (size < 5 || size > 20) {
        std::cerr << "Invalid map size";
        std::cerr << std::endl;
        exit(1);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "usage: ./smartPointers [width] [height]";
        std::cerr << std::endl;
        exit(1);
    }
    size_t width = getSize(argv[1]);
    checkRange(width);
    size_t height = getSize(argv[2]);
    checkRange(height);
    std::shared_ptr<Player> play(new Player);
    std::shared_ptr<Map> map(new Map(width, height, play));
    MoveManager move(play, map);
    while (1) {
        std::string comand;
        std::getline(std::cin, comand);
        move.processInputAndMove(comand);
    }
    return 0;
}
