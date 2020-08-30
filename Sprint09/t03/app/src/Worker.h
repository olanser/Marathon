#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <vector>


class Worker {
    public:
        Worker() = default;
        ~Worker() {joinAllThreads();}
        
        template <typename Function, class... Args>
        void startNewThread(Function&& func, Args&&...args) {
            m_workerThreads.push_back(std::thread(func, args...));
        }

        void joinAllThreads() {
            for (auto & temp : m_workerThreads) {
                temp.join();
            }
            m_workerThreads.clear();
        }
    private:
        std::vector<std::thread> m_workerThreads;
};
