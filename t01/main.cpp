#include "moveAlong.h"

bool checkStrinng(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (str.find("mercer", 0) != std::string::npos)
        return true;
    if (str.find("emer", 0) != std::string::npos)
        return true;
    if (str.find("jim", 0) != std::string::npos)
        return true;
    return false;
}

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "usage: ./moveAlong [args]" << std::endl;
        return 1;
    }
    else {
        std::vector<std::string> vect;
        for (auto i = 1; i < argc; i++)
            vect.push_back(argv[i]);
        std::vector<std::string>::iterator it = vect.begin();
        while (it != vect.end()) {
            it = std::find_if(it, vect.end(), checkStrinng);
            if (it != vect.end()) {
                std::cout << *it << ", move along!" << std::endl;
                it++;
            }
        }
    }
    return 0;
}
