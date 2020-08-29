#include "SomeClass.h"
#include "Serializer.h"

void fiveArgc(char** argv) {
    Serializer ser;
    size_t pos;

    int intVal = std::stoi(std::string(argv[2]), &pos);
        if (argv[2][pos] != '\0')
            throw 1;
    float floatVal = std::stof(std::string(argv[4]), &pos);
        if (argv[4][pos] != '\0')
            throw 1;
    if (!(argv[3][0] != 0 && argv[3][1] == 0))
        throw 1;
    char charVal = argv[3][0];
    SomeClass newSomeClass(intVal, charVal, floatVal);
    ser.serialize<SomeClass>(&newSomeClass, argv[1]);
    std::cout << "SomeClass: ";
    newSomeClass.output();
    std::cout << " serialized"<< std::endl;
}

void threeArgc(char** argv) {
    Serializer ser;
    size_t pos;

    if (std::string(argv[1]) == "int") {
        int temp = std::stoi(std::string(argv[2]), &pos);
        if (argv[2][pos] != '\0')
            throw 1;
        ser.serialize(&temp, "int");
        std::cout << "int: " << temp << " serialized"<< std::endl;
    }
    else if (std::string(argv[1])  == "float") {
        float temp = std::stof(std::string(argv[2]), &pos);
        if (argv[2][pos] != '\0')
            throw 1;
        ser.serialize(&temp, "float");
        std::cout << "float: " << temp << " serialized"<< std::endl;
    }
    else
        throw 1;
}

int main(int argc, char** argv) {
    if (argc > 5 || argc == 1 || argc == 4) {
        std::cerr << "./serializer [anyFileName] [intVal] [charVal] [floatVal]" << std::endl;
        exit(1);
    }
    try {
        Serializer ser;
        if (argc == 2) {
            if (std::string(argv[1]) == "int") {
                int temp = ser.deserialize<int>("int");
                std::cout << "Deserialized int: " << temp << std::endl;
            }
            else if (std::string(argv[1]) == "float") {
                float temp = ser.deserialize<float>("float");
                std::cout << "Deserialized float: " << temp << std::endl;
            }
            else {
                SomeClass temp = ser.deserialize<SomeClass>(argv[1]);
                std::cout << "Deserialized SomeClass: " ;
                temp.output();
                std::cout << std::endl;
            }
        }
        else if (argc == 3) {
            threeArgc(argv);
        }
        else {
            fiveArgc(argv);
        }
    }
    catch (...) {
        std::cerr << "error" << std::endl;
            exit(1); 
    }
}