#pragma one

#include <set>
#include <regex>
#include <sstream>

#include "printError.h"
#include "checkArgument.h"
#include "openFile.h"
#include "creaneNameNewFile.h"

void addNewWordToSet(std::ifstream& readFile,
                     std::set<std::string>& listName);
void writeFileUniqueWords(std::ofstream& writeFile,
                          std::set<std::string>& listName);