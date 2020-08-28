#pragma once

#include <iostream>
#include <vector>



template <typename T>

class ClassWithInitializerList final {
    public:
        template <typename... Args>
        ClassWithInitializerList(Args&&... args): m_vecOfArs({args...}) {
        }
        ClassWithInitializerList(const std::initializer_list<T> lst): m_vecOfArs(lst.begin(), lst.end()) {
        }
        ClassWithInitializerList(const std::vector<T>& vec) : m_vecOfArs((vec.begin(), vec.end())) {
        }
        
        void outputVector() const {
            for (auto &temp: m_vecOfArs)
                std::cout << temp << std::endl;
        }
    private:
        std::vector<T> m_vecOfArs;
};
