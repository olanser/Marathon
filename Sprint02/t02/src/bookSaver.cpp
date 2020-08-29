#include "bookSaver.h"

void printComandEnter(void) {
    std::cout << "enter command:> ";
}

std::string getOneCommand(std::stringstream& ss) {
    std::string str;
    while (ss.peek() == ' ')
        ss.ignore();
    ss >> str;
    while (ss.peek() == ' ')
        ss.ignore();
    return str;
}

void check(std::string comand) {
    std::cout << comand << std::endl;
}

void checkComand(std::map<std::string, std::string>& listBook) {
    std::string lineCommand;
    std::string argv1;
    std::string checkStr;

    std::getline(std::cin, lineCommand);
    std::stringstream ss(lineCommand);
    lineCommand = getOneCommand(ss);
    if (lineCommand.size() == 0)
        return;
    argv1 = getOneCommand(ss);
    checkStr = getOneCommand(ss);
    if (lineCommand == "quit" && argv1.size() == 0)
        commandQuit();
    else if (lineCommand == "list" && argv1.size() == 0)
        commandList(listBook);
    else if (lineCommand == "add" && argv1.size() > 0 && checkStr.size() == 0)
        commandAdd(listBook, argv1);
    else if (lineCommand == "delete" && argv1.size() > 0 
             && checkStr.size() == 0) {
        commandDelete(listBook, argv1);
    }
    else if (lineCommand == "read" && argv1.size() > 0 
             && checkStr.size() == 0) {
        commandRead(listBook, argv1);
    }
    else
        std::cout << "invalid command" << std::endl;
}
