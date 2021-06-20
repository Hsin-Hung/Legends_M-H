#include "Common.h"

Common::Common() : Space(true, Common_T) {}

void Common::triggerEvent(std::unique_ptr<Hero> &hero)
{
    std::cout << *this << std::endl;
}

void Common::display(std::ostream &os) const
{
    os << " ";
}