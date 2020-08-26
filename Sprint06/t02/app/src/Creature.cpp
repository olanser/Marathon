#include "Creature.h"

Creatures::Creature::Creature(const std::string& name) 
    : m_name(name), m_health(100), m_mana(100)
{
};

void Creatures::Creature::learnSpell(Spells::ISpell* spell) {
    if (spell != nullptr) {
        if (m_spells.count(spell)) {
            std::cout << m_name << " already knows " << spell->getType() << " spell!" << std::endl;
        }
        else {
            m_spells.insert(spell);
            std::cout << m_name << " has learned " << spell->getType() << " spell successfully!" << std::endl;
        }
    }
}

void Creatures::Creature::castSpell(const Spells::SpellType type, Creature& creature) {
    for (auto& spellPtr: m_spells) {
        if (spellPtr->getType() == type) {
            if (spellPtr->cast(*this, creature)) {
                std::cout << m_name << " casted " << type << " spell on " << creature.getName() << std::endl;
            }
            else {
                std::cout << m_name << " can't cast " << type << std::endl;
            }
            return;
        }
    }
    std::cout << type<< " spell is not learned by " << m_name  << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Creatures::Creature& creature) {
    os << creature.getName() << " : " << creature.getHealth() << " HP, " << creature.getMana() << " MP";
    return os;
}

std::string Creatures::Creature::getName() const {
    return m_name;
}

int Creatures::Creature::getHealth() const {
    return m_health;
}

int Creatures::Creature::getMana() const {
    return m_mana;
}
    
void Creatures::Creature::setHealth(int health) {
    m_health = health;
}
    
void Creatures::Creature::setMana(int mana) {
    m_mana = mana;
}

Imperial::Imperial(const std::string& name) : Creatures::Creature::Creature(name) {
    std::cout << getName() << " was born!" << std::endl;
}

Redguard::Redguard(const std::string& name) : Creatures::Creature::Creature(name) {
    std::cout << getName() << " was born!" << std::endl;
}

void Imperial::sayPhrase() const {
    std::cout << "I am " << getName() << ", Imperial soldier! Stop right here!\n";
}

void Redguard::sayPhrase() const {
    std::cout << "I am " << getName() << " from Redguards, wanna trade?\n";
}
