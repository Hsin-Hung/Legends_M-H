#include "Paladin.h"

Paladin::Paladin(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Hero(name, mana, strength, agility, dexterity, money, exp) {}

void Paladin::display(std::ostream &os) const
{
    os << name;
}