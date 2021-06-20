#include "Space.h"

Space::Space(bool accessible, SpaceType type) : accessible{accessible}, type{type} {}

SpaceType Space::getType()
{
    return type;
}

bool Space::isAccessible()
{
    return accessible;
}