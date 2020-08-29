#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Serializer {
    public:
        template <class T>
        void serialize(const T* object, const std::string& fileName) {
            std::ofstream ss(fileName, std::ios::binary);
            if (ss) {
                ss.write(reinterpret_cast<const char*>(object), sizeof(T));
                ss.close();
            }
            else {
                std::cerr << "error" << std::endl;
                exit(1);
            }
        }
        
        template <class T>
        T deserialize(const std::string& fileName) {
            std::ifstream ss(fileName, std::ios::binary);
            T object;
            if (ss) {
                ss.read(reinterpret_cast<char*>(&object), sizeof(T));
                ss.close();
            }
            else {
                throw 1;
            }
            return object;
        }
};
