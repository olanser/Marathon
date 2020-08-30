#include "src/Worker.h"
#include "src/ClassWithAtomic.h"

int getValue(const std::string& str) {
    size_t pos;
    int vel = std::stoi(str, &pos);
    if (str[pos] != 0)
        throw 1;
    return vel;
}

int main(int argc, char** argv) {
    //...
    if (argc != 4) {
        std::cerr << "usage: classWithAtomic [add] [subtract] [size]" << std::endl;
        return 1;
    }
    int addValue;
    int pushSize;
    int subtractValue;
    try {
        addValue = getValue(argv[1]);
        subtractValue = getValue(argv[2]);
        pushSize = getValue(argv[3]);
    }
    catch (...) {
        std::cerr << "usage: classWithAtomic [add] [subtract] [size]" << std::endl;
        return 1;
    }
    Worker worker;
    ClassWithAtomic obj;
    worker.startNewThread(&ClassWithAtomic::addToInt, &obj, addValue);
    worker.startNewThread(&ClassWithAtomic::subtractFromInt, &obj, subtractValue);
    
    for (auto i = 0; i < pushSize; ++i) {
        worker.startNewThread(&ClassWithAtomic::pushToVector, &obj, i);
    }
    
    for (auto i = 1; i <= pushSize; ++i) {
        if (i % 2 == 0) {
            worker.startNewThread(&ClassWithAtomic::eraseFromVector, &obj, i);
        }
    }
    
    worker.joinAllThreads();
    std::cout<< "Result: "<< obj.getInt() << std::endl;
    auto vec = obj.getVector();
    std::cout<< "Size of vector: "<< vec.size() << std::endl;
    for (int i = 0; i < vec.size();++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << " "  ;
        } else {
            std::cout<< std::endl;
        }
    }
    //...
}
