#include "Characters/Sorcerer.h"
#include "Utils/ColoredText.h"

Sorcerer::Sorcerer(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Hero(name, mana, strength, agility, dexterity, money, exp) {}

void Sorcerer::display(std::ostream &os) const
{
    os << ColoredText::green(name);
}

void Sorcerer::subStatsUp(double percentage)
{

    strength *= (1.0 + percentage);
    agility *= (1.05 + percentage);
    dexterity *= (1.05 + percentage);
}