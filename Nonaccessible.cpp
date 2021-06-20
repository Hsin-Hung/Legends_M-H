#include "Nonaccessible.h"
#include <iostream>

Nonaccessible::Nonaccessible() : Space(false, Inaccessible_T){};

void Nonaccessible::triggerEvent(std::unique_ptr<Hero> &hero)
{
    std::cout << *this << std::endl;
}

void Nonaccessible::display(std::ostream &os) const
{
    os << "X";
}