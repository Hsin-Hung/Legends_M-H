#include "Spaces/Space.h"

Space::Space(bool accessible, SpaceType type) : type{type}, accessible{accessible} {}

SpaceType Space::getType() const
{
    return type;
}

bool Space::isAccessible() const
{
    return accessible;
}