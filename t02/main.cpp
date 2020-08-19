#include "visitAll.h"

static City createCity(std::stringstream& ss, std::string argument, int pos) {
    std::string name;
    std::string stamina;
    std::string distance;
    int stam;
    int dist;
    size_t idx;
    try {
        if (std::getline(ss, name,  ',') && std::getline(ss, stamina,  ',')
            && std::getline(ss, distance) && name.size() > 0) {
            stam = std::stoi(stamina, &idx, 10);
            if (stamina[idx] != 0)
                throw 1;
            dist = std::stoi(distance, &idx, 10);
            if (distance[idx] != 0)
                throw 1;
            if (stam < 0 || dist < 0)
                throw 1;
        }
        else
            throw 1;
    }
    catch (...) {
        std::cerr << "Argument " << argument << " is not valid" << std::endl;
        exit(1);
    }
    City town(pos, name, stam, dist);
    return  town;
}


static void printVisitAll(std::deque<City>& listTown) {
    for (auto tempTown: listTown) {
        std::cout << tempTown.pos <<  ". " << tempTown.name << std::endl;
    }
    exit(0);
}

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]";
        std::cerr << std::endl;
        return 1;
    }
    else {
        std::deque<City> listTown;
        for (int i; i < argc; i++) {
            std::stringstream ss(argv[i]);
            City newTown = createCity(ss, argv[i], i - 1);
            listTown.push_back(newTown);
        }
        for (int i = 0; i < argc - 1; i++) {
            int actualSnamina = 0;
            for (int j = 0; j < argc - 1; j++) {
                if ((actualSnamina += listTown[j].stamina - listTown[j].dist) < 0 
                    && i != argc - 2) {
                    break;
                    }
                if (j == argc - 2)
                    printVisitAll(listTown);
            }
            listTown.push_back(listTown[0]);
            listTown.pop_front();
        }
    }
    std::cerr << "Mission: Impossible" << std::endl;
    return 1;
}
