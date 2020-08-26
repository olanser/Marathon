#include "Creature.h"

bool Spells::Healing::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    if (owner.getMana() >= 15) {
        owner.setMana(owner.getMana() - 15);
        owner.setHealth(owner.getHealth() + 15);
        return true;
    }
    return false;
}

bool Spells::Equilibrium::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    owner.setMana(owner.getMana() + 25);
    owner.setHealth(owner.getHealth() - 25);
    return true;
}

bool Spells::Flames::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    if (owner.getMana() >= 14) {
        owner.setMana(owner.getMana() - 14);
        other.setHealth(owner.getHealth() - 8);
        return true;
    }
    return false;

}


bool Spells::Freeze::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    if (owner.getMana() >= 30) {
        owner.setMana(owner.getMana() - 30);
        other.setHealth(other.getHealth() - 20);
        return true;
    }
    return false;
}

bool Spells::Fireball::cast(Creatures::Creature& owner, Creatures::Creature& other) {
    if (owner.getMana() >= 50) {
        owner.setMana(owner.getMana() - 50);
        other.setHealth(owner.getHealth() - 40);
        return true;
    }
    return false;
}

Spells::SpellType Spells::Healing::getType() const {
    return SpellType::Healing;
}

Spells::SpellType Spells::Equilibrium::getType() const {
    return SpellType::Equilibrium;
}

Spells::SpellType Spells::Flames::getType() const {
    return SpellType::Flames;
}

Spells::SpellType Spells::Freeze::getType() const {
    return SpellType::Freeze;
}

Spells::SpellType Spells::Fireball::getType() const {
    return SpellType::Fireball;
}

std::ostream& operator<< (std::ostream &out, const Spells::SpellType& type) {
    switch (type)
    {
    case Spells::SpellType::Healing :
        out << "healing";
        break;
    case Spells::SpellType::Equilibrium :
        out << "equilibrium";
        break;
    case Spells::SpellType::Flames :
        out << "flames";
        break;
    case Spells::SpellType::Freeze :
        out << "freeze";
        break;
    case Spells::SpellType::Fireball :
        out << "fireball";
        break;
    }
    return out;
}

bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs) {
    if (lhs.getType() == rhs.getType())
        return true;
    return false;
}
