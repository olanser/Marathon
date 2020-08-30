#pragma once

#include <iostream>
#include <string>
#include <future>


class Worker {
    public:
        Worker() = default;
        ~Worker() = default;
        template <typename Function, class... Args>
        auto startAsync(Function&& func, Args&&... args) {
            return std::async(std::launch::async, func, args...);
        }
};
