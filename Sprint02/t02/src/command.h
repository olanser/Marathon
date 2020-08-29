#pragma one

#include <iostream>
#include <map>
#include <fstream>

#include "openFile.h"


void commandQuit(void);
void commandList(const std::map<std::string, std::string>& listBook);
void commandAdd(std::map<std::string, std::string>& listBook,
                const std::string& book);
void commandDelete(std::map<std::string, std::string>& listBook,
                const std::string& book);
void commandRead(std::map<std::string, std::string>& listBook,
                const std::string& book);
