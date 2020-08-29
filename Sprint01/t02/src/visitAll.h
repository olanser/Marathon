#pragma once

#include <iostream>
#include <sstream>
#include <deque>

struct City {
    City(int p, std::string n, int s, int d) {
        pos = p;
        name = n;
        stamina = s;
        dist = d;
    }
    int pos;
    std::string name;
    int stamina;
    int dist;
};