#include "SmartPointers.h"

size_t Player::posX() const {
    return m_posX;
}

size_t Player::posY() const {
    return m_posY;
}

void Player::movePlayer(MoveManager::Direction dir) {
    switch (dir) {
        case MoveManager::Direction::Up: {
            --m_posY;
            break;
        }
        case MoveManager::Direction::Down: {
            ++m_posY;
            break;
        }
        case MoveManager::Direction::Left: {
            --m_posX;
            break;
        }
        default: {
            ++m_posX;
            break;
        }
    } 
}

char Player::getIdentifier() const {
    return 'P';
}