#include "countUniqueWords.h"

int main(int argc, char** argv) {
    checkArgument(argc, 2, "usage: ./countUniqueWords [file_name]");

    std::ifstream readFile;
    if (!openFileRead(readFile, argv[1]))
        printError("error");
    std::multiset<std::string> listName;
    addNewWordToMultiset(readFile, listName);
    if (listName.size() == 0)
        printError("error");
    std::string newName = creaneNameNewFile(argv[1], "_mod");
    std::ofstream writeFile;
    if (!openFileWrite(writeFile, newName))
        printError("error");
    writeFileCountUniqueWords(writeFile, listName);
    return 0;
}
