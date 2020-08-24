#include "checkArgument.h"

void checkArgument(int count, int isCount, const std::string &error) {
    if (count != isCount) {
        std::cerr << error << std::endl;
        exit(1);
    }
}
