#include "draugrII.h"

Draugr::Draugr() : Draugr::Draugr(100, 50) {}

Draugr::Draugr(int frostResist) : Draugr::Draugr(100, frostResist) {
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
    std::cout << "Draugr (" << m_health << " health, " << m_frostResist;
    std::cout << "% frost resist) shouts:\n" << list[shoutNumber] << std::endl;
}
