#include "Paladin.h"

Paladin::Paladin(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Hero(name, mana, strength, agility, dexterity, money, exp) {}

void Paladin::display(std::ostream &os) const
{
    os << name;
}

void Paladin::subStatsUp(double percentage)
{

    strength *= (1.05 + percentage);
    agility *= (1.0 + percentage);
    dexterity *= (1.05 + percentage);
}