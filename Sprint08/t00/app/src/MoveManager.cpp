#include "SmartPointers.h"

MoveManager::MoveManager(std::shared_ptr<Player>& player, std::shared_ptr<Map>& map)
    : m_map(map), m_player(player) {

}


void MoveManager::processInputAndMove(const std::string& inputStr) {
    std::stringstream ss(inputStr);
    std::string comand;
    Direction key;

    if (!((ss >> comand) && ss.peek()) != 0) {
        std::cerr << "Invalid direction" << std::endl;
        return;
    }
    else {
        if (comand == "u")
            key = Direction::Up;
        else if (comand == "d")
            key = Direction::Down;
        else if (comand == "r")
            key = Direction::Right;
        else if (comand == "l")
            key = Direction::Left;
        else if (comand == "e")
            exit(0);
        else {
            std::cerr << "Invalid direction" << std::endl;
            m_map->outputMap();
            return;
        }
    }
    if (checkMove(key)) {
        m_player->movePlayer(key);
    }
    else
        std::cerr << "Invalid direction" << std::endl;
    m_map->outputMap();
}

bool MoveManager::checkMove(Direction dir) const {
    switch (dir) {
        case Direction::Up: {
            if (m_player->posY() == 0)
                return false;
            return true;
            break;
        }
        case Direction::Down: {
            if (m_player->posY() == m_map->height() - 1)
                return false;
            return true;
            break;
        }
        case Direction::Left: {
            if (m_player->posX() == 0)
                return false;
            return true;
            break;
        }
        default: {
            if (m_player->posX() == m_map->width() - 1)
                return false;
            return true;
            break;
        }  
    }
    return false;
}