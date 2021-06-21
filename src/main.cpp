#include "Spaces/World.h"
#include "Characters/MonsterFactory.h"
#include "Characters/HeroFactory.h"
#include "Spaces/Market.h"
#include <iostream>
#include <iomanip>

int main()
{
    World world(8);
    world.initWorld();

    return 0;
}