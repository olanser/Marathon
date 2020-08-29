#include "tesLibrary.h"


int main(int argc, char** argv) {
    checkArgument(argc, 2, "usage: ./tesLibrary [file_name]");

    std::ifstream readFile;
    if (!openFileRead(readFile, argv[1]))
        printError("error");
    std::multimap<std::string, std::string> listName;
    addNewWordToMultimap(readFile, listName);
    writeBookToAutor(listName);
}
//     addNewWordToSet(readFile, listName);
//     if (listName.size() == 0)
//         printError("error");
//     std::string newName = creaneNameNewFile(argv[1], "_mod");
//     std::ofstream writeFile;
//     if (!openFileWrite(writeFile, newName))
//         printError("error");
//     writeFileUniqueWords(writeFile, listName);
//     return 0;
// }
