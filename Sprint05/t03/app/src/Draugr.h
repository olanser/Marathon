#pragma once

#include <iostream>
#include <vector>

class Draugr {
public:
    Draugr();
    Draugr(int frostResist);
    Draugr(double health, int frostResist = 50);
    Draugr(Draugr& other) = delete;
    Draugr(Draugr&& other) = delete;
    
    void setName(const std::string&& name);
    void shoutPhrase(int shoutNumber) const;
    
private:
    double m_health;
    const int m_frostResist;
    std::string m_name;
};
