#include "Exoskeleton.h"

Exoskeleton::Exoskeleton(std::string name, int level, int damage, int defense, int dodge)
    : Monster(name, level, damage, defense, dodge)
{
}

void Exoskeleton::display(std::ostream &os) const
{
    os << name;
}