#include "uniqueWords.h"

int main(int argc, char** argv) {
    checkArgument(argc, 2, "usage: ./uniqueWords [file_name]");

    std::ifstream readFile;
    if (!openFileRead(readFile, argv[1]))
        printError("error");
    std::set<std::string> listName;
    addNewWordToSet(readFile, listName);
    if (listName.size() == 0)
        printError("error");
    std::string newName = creaneNameNewFile(argv[1], "_mod");
    std::ofstream writeFile;
    if (!openFileWrite(writeFile, newName))
        printError("error");
    writeFileUniqueWords(writeFile, listName);
    return 0;
}
