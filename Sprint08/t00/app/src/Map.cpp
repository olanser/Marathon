#include "SmartPointers.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player>& player)
    : m_player(player), m_width(width), m_height(height), m_map(new char[width * height])
{
    generateMap();
}


void Map::generateMap() {
    srand (time(NULL));
    size_t size = m_width * m_height;
    auto pointer = m_map.get();
    for (int i = 0; i < size; ++i)
        *(pointer  + i) = '.';
    for (int i = m_width; i >=0 ; --i)
        *(pointer + std::rand() % size) = 'T';
    for (int i = m_height; i >=0 ; --i)
        *(pointer + std::rand() % size) = '@';
    outputMap();
}


size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}

void Map::outputMap() const {
    size_t size = m_width * m_height;
    size_t posUser = m_player->posY() * m_width + m_player->posX();
    auto pointer = m_map.get();
    for (int i = 0; i < size; ++i) {
        if (i == posUser)
            std::cout << m_player->getIdentifier();
        else {
            std::cout << *(pointer + i);
        }
        if (((i + 1) % m_width) == 0)
            std::cout << std::endl;
    }
    std::cout << ":> ";
}
