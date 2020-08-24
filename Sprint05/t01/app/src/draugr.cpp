#include "draugrII.h"

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
    std::cout << "Draugr (" << m_health << " health, " << m_frostResist;
    std::cout << "% frost resist) shouts:\n" << list[shoutNumber] << std::endl;
}
