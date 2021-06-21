#include "Spaces/Nonaccessible.h"
#include "Utils/ColoredText.h"
#include <iostream>

Nonaccessible::Nonaccessible() : Space(false, Inaccessible_T){};

void Nonaccessible::triggerEvent(std::unique_ptr<Hero> &hero)
{
}

void Nonaccessible::display(std::ostream &os) const
{
    os << ColoredText::white("X");
}

std::string Nonaccessible::getSymbol() const
{
    return ColoredText::white("X");
}