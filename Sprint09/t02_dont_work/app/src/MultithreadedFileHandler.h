#pragma once
#include <mutex>
#include <string>
#include <condition_variable>
#include <fstream>
#include <unistd.h>

class MultithreadedFileHandler {
    public:
        MultithreadedFileHandler() = default;
        ~MultithreadedFileHandler() = default;
        
        void processFile() {
            std::unique_lock<std::mutex> lck(m_mutex);
            while (m_fileLoaded) {
                m_condVar.wait(lck);
                std::cout << "-----1 second sleep-----\n";
                sleep(1);
            }
            m_fileLoaded = true;
        }

        void loadFile(const std::string& fileName) {
            processFile();

            std::ifstream ss(fileName);
            if (!ss) {
                std::cerr << "error\n";
                exit(1);
            }
            std::string temp;

            while (getline(ss, temp))
                std::cout << temp << "\n";
            std::unique_lock<std::mutex> lck(m_mutex);
            m_condVar.native_handle
            m_fileLoaded = false;
            m_condVar.notify_one();
        }
    private:
        std::string m_file;
        std::mutex m_mutex;
        std::condition_variable m_condVar;
        bool m_fileLoaded{false};
};