#include "Spirit.h"

Spirit::Spirit(std::string name, int level, int damage, int defense, int dodge)
    : Monster(name, level, damage, defense, dodge)
{
}

void Spirit::display(std::ostream &os) const
{
    os << name;
}