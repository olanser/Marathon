#pragma once
#include <mutex>
#include <string>
#include <condition_variable>
#include <fstream>
#include <vector>

class ClassWithAtomic {
    public:
        ClassWithAtomic() = default;
        ~ClassWithAtomic() = default;
        
        void addToInt(int addValue) {
            for (auto i = 0; i < addValue; i++)
                ++m_int;
        }
        void subtractFromInt(int subtractValue) {
            for (auto i = 0; i < subtractValue; i++)
                --m_int;
        }
        void pushToVector(int value) {
            m_vecMutex.lock();
            m_vector.push_back(value);
            m_vecMutex.unlock();
        }
        void eraseFromVector(int value) {
            m_vecMutex.lock();
            m_vector = {m_vector.begin(), std::remove(m_vector.begin(), m_vector.end(), value)};
            m_vecMutex.unlock();
        }
        
        int getInt() const {
            return m_int;
        }
        std::vector<int> getVector() const {
            return m_vector;
        }
        
    private:
        std::mutex m_vecMutex;
        std::atomic<int> m_int;
        std::vector<int> m_vector;
};
