#include "Market.h"

Market::Market() : Space(true) {}

void Market::triggerEvent()
{
}

void Market::display(std::ostream &os) const
{
    os << "M";
}