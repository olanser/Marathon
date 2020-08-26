#pragma once
namespace Creatures {
    class Creature;
};

#include <iostream>

namespace Spells {

enum class SpellType {
    Healing,
    Equilibrium,
    Flames,
    Freeze,
    Fireball
};   
 
class ISpell {
public:
    virtual ~ISpell() = default;
    
    virtual bool cast(Creatures::Creature& owner, Creatures::Creature& other) = 0;
    virtual SpellType getType() const= 0;
};


class Healing : public ISpell {
    SpellType getType() const;

    bool cast(Creatures::Creature& owner, Creatures::Creature& other);
};

class Equilibrium : public ISpell {
    SpellType getType() const;

    bool cast(Creatures::Creature& owner, Creatures::Creature& other);
};

class Flames : public ISpell {
    SpellType getType() const;

    bool cast(Creatures::Creature& owner, Creatures::Creature& other);
};

class Freeze : public ISpell {
    SpellType getType() const;

    bool cast(Creatures::Creature& owner, Creatures::Creature& other);
};

class Fireball : public ISpell {
    SpellType getType() const;

    bool cast(Creatures::Creature& owner, Creatures::Creature& other);
};


} // end namespace Spells

bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs);

// bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs) {
//     if (lhs.getType() == rhs.getType())
//         return true;
//     return false;
// }

std::ostream& operator<< (std::ostream &out, const Spells::SpellType& type);

// std::ostream& operator<< (std::ostream &out, const Spells::SpellType& type) {
//     switch (type)
//     {
//     case Spells::SpellType::Healing :
//         out << "Healing";
//         break;
//     case Spells::SpellType::Equilibrium :
//         out << "Equilibrium";
//         break;
//     case Spells::SpellType::Flames :
//         out << "Flames";
//         break;
//     case Spells::SpellType::Freeze :
//         out << "Freeze";
//         break;
//     case Spells::SpellType::Fireball :
//         out << "Fireball";
//         break;
//     }
//     return out;
// }
