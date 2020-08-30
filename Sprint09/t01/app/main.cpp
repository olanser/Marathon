#include "Worker.h"
#include "MultithreadedClass.h"

int main(int argc, char** argv) {
    int addValue;
    int subtractValue;
    int count;

    if (argc != 4) {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]" << std::endl;
        exit(1);
    }
    try {
        size_t pos;
        addValue = std::stoi(std::string(argv[1]), &pos);
        if (argv[1][pos] != '\0')
            throw 1;
        subtractValue = std::stoi(std::string(argv[2]), &pos);
        if (argv[2][pos] != '\0')
            throw 1;
        count = std::stoi(std::string(argv[3]), &pos);
        if (argv[3][pos] != '\0')
            throw 1;
        if (addValue > 2000 || addValue < -2000 || subtractValue > 2000
            || subtractValue < -2000 || count > 10 || count < 5)
            throw 1;
        
    }
    catch (...) {
        std::cerr << "Incorrect values" << std::endl;
        exit(1);
    }
    MultithreadedClass obj;
    Worker worker;
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
    }
    
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
    }

    worker.joinAllThreads();
    
    std::cout << obj.getInt() << std::endl;
    //...
}