#include "bookSaver.h"

int main() {
    std::map<std::string, std::string> listBook;
    while (1) {
        printComandEnter();
        checkComand(listBook);
    }
    return 0;
}