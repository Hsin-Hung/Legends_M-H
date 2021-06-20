#include "Dragon.h"

Dragon::Dragon(std::string name, int level, int damage, int defense, int dodge)
    : Monster(name, level, damage, defense, dodge)
{
}

void Dragon::display(std::ostream &os) const
{
    os << name;
}