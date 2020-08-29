#pragma one

#include <set>
#include <regex>
#include <sstream>

#include "printError.h"
#include "checkArgument.h"
#include "openFile.h"
#include "creaneNameNewFile.h"

void addNewWordToMultiset(std::ifstream& readFile,
                     std::multiset<std::string>& listName);
void writeFileCountUniqueWords(std::ofstream& writeFile,
                          std::multiset<std::string>& listName);