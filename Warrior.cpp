#include "Warrior.h"

Warrior::Warrior(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Hero(name, mana, strength, agility, dexterity, money, exp) {}

void Warrior::display(std::ostream &os) const
{
    os << name;
}