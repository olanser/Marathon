#include "draugrIII.h"

Draugr::Draugr() : m_frostResist(50), m_health(100) {
    std::cout << "Draugr with " << m_health << " health and " << m_frostResist;
    std::cout << "% frost resist was born!" << std::endl;
}

Draugr::Draugr(int frostResist) : m_frostResist(frostResist), m_health(100) {
    std::cout << "Draugr with " << m_health << " health and " << m_frostResist;
    std::cout << "% frost resist was born!" << std::endl;
}

Draugr::Draugr(double health, int frostResist) 
    : m_frostResist(frostResist), m_health(health) {
    std::cout << "Draugr with " << m_health << " health and " << m_frostResist;
    std::cout << "% frost resist was born!" << std::endl;
}

Draugr::Draugr(Draugr& other) 
    : m_health(other.m_health), m_frostResist(other.m_frostResist) 
    {
    std::cout << "Draugr with " << m_health << " health and " << m_frostResist;
    std::cout << "% frost resist was born!" << std::endl;
    std::cout << "Copy constructor was called" << std::endl;
}


Draugr::Draugr(Draugr&& other) 
    : m_health(other.m_health), m_frostResist(other.m_frostResist)
    {
    std::cout << "Draugr with " << m_health << " health and " << m_frostResist;
    std::cout << "% frost resist was born!" << std::endl;
    std::cout << "Move constructor was called" << std::endl;
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}

void Draugr::shoutPhrase(int shoutNumber) const {
    std::vector<std::string> list = {"Qiilaan Us Dilon!",
                                     "Bolog Aaz, Mal Lir!",
                                     "Kren Sosaal!",
                                     "Dir Volaan!",
                                     "Aar Vin Ok!",
                                     "Unslaad Krosis!",
                                     "Faaz! Paak! Dinok!",
                                     "Aav Dilon!",
                                     "Sovngarde Saraan!"
                                    };
    if (shoutNumber < 0 || shoutNumber > 8) {
        std::cerr << "Invalid shoutNumber" << std::endl;
        exit(1);
    }
    std::cout << "Draugr " << m_name << " (" << m_health << " health, ";
    std::cout << m_frostResist  << "% frost resist) shouts:\n";
    std::cout << list[shoutNumber] << std::endl;
}
