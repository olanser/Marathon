#include "printError.h"

void printError(const std::string& error) {
    std::cerr << error << std::endl;
    exit(1);
}
