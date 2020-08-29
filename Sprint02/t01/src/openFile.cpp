#include "openFile.h"

bool openFileRead(std::ifstream &stream, std::string fileName) {
    stream.open(fileName);
    if (stream.is_open())
        return true;
    return false;
}

bool openFileWrite(std::ofstream &stream, std::string fileName) {
    stream.open(fileName);
    if (stream.is_open())
        return true;
    return false;
}
