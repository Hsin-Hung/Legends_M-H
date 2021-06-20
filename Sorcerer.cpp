#include "Sorcerer.h"

Sorcerer::Sorcerer(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Hero(name, mana, strength, agility, dexterity, money, exp) {}

void Sorcerer::display(std::ostream &os) const
{
    os << name;
}