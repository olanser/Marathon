#include "dragonborn.h"


int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]";
        std::cerr << std::endl;
        exit(1);
    }
    Dragonborn a;
    std::map<std::string, Dragonborn::Actions> mapActions = {
        {"shout", Dragonborn::Actions::Shout},
        {"magic", Dragonborn::Actions::Magic},
        {"weapo", Dragonborn::Actions::Weapon}
    };
    try {
        a.executeAction(mapActions.at(argv[1]));
    }
    catch (...){
        std::cerr << "Invalid action" << std::endl;
        exit(1);
    }
    return 0;
}