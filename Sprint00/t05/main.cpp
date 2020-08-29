#include <iostream>

void checkEndLine(char *str, size_t pos) {
    if (str[pos] != 0)
        throw 1;
}

void printUser(char *name, int level, float health, double stamina) {
    std::cout << "Name = " << name << std::endl;
    std::cout << "Level = " << level << std::endl;
    std::cout << "Health = " << health << std::endl;
    std::cout << "Stamina = " << stamina << std::endl;
}

int main(int argc, char** argv) {
    auto pos = 2;

    if (argc != 5) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]";
        std::cerr << std::endl;
        return 1;
    }
    try {
        auto idx = 4294967295ul;
        auto level = std::stoi(argv[pos], &idx, 10);
        checkEndLine(argv[pos], idx);
        auto health = std::stof(argv[++pos], &idx);
        checkEndLine(argv[pos], idx);
        auto stamina = std::stod(argv[++pos], &idx);
        checkEndLine(argv[pos], idx);
        printUser(argv[1], level, health, stamina);
    }
    catch (...) {
        std::cerr << "invalid argument: " << argv[pos] << std::endl;
        return 1;
    }
    return 0;
}
