#pragma once
#include <iostream>

class SomeClass {
    public:
        SomeClass() = default;
        SomeClass(int intVal, char charVal, float floatVal)
            : m_charArg(charVal), m_intArg(intVal), m_floatArg(floatVal) {

            }
        void output() const {
            std::cout << m_intArg << " " << m_charArg << " " << m_floatArg;
        }
        
    private:
        int m_intArg;
        char m_charArg;
        float m_floatArg;
};
