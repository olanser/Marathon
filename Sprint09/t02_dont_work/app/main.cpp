#include "src/Worker.h"
#include "MultithreadedFileHandler.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]\n";
        exit(1);
    }

    MultithreadedFileHandler handler;
    Worker worker;
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &handler, argv[1]);
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &handler, argv[2]);
}
