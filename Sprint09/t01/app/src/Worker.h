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
            while (m_workerThreads.size() > 0) {
                m_workerThreads[m_workerThreads.size() - 1].join();
                m_workerThreads.pop_back();
            }
        }
    private:
        std::vector<std::thread> m_workerThreads;
};
