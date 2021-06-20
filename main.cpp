#include "World.h"
#include "MonsterFactory.h"
#include "HeroFactory.h"
#include "Market.h"
#include <iostream>
#include <iomanip>

int main()
{
    World world(8);
    world.initWorld();
    return 0;
}