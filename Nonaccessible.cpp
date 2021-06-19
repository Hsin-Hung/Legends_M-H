#include "Nonaccessible.h"

Nonaccessible::Nonaccessible() : Space(false){};

void Nonaccessible::triggerEvent()
{
}

void Nonaccessible::display(std::ostream &os) const{
    os << "X";
}