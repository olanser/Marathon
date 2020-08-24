#include "draugr.h"
#include "checkArgument.h"
#include "printError.h"

int main(int argc, char** argv) {
    checkArgument(argc, 2, "usage: ./draugr [shoutNumber]");

    try {
        size_t pos = 0;
        int value = std::stoi(argv[1], &pos, 10);
        if (argv[1][pos] != '\0')
            throw 1;
        Draugr check;
        check.shoutPhrase(value);
    }
    catch (...) {
        printError("Invalid shoutNumber");
    }
    return 0;
}