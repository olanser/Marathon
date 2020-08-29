#pragma once


#include <map>
#include <regex>

#include "checkArgument.h"
#include "openFile.h"
#include "printError.h"

void addNewWordToMultimap(std::ifstream& readFile,
                          std::multimap<std::string, std::string>& listName);
void writeBookToAutor(std::multimap<std::string, std::string>& listName);
