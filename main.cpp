#include "World.h"
#include "MonsterFactory.h"
#include <iostream>
#include <iomanip>

int main()
{

    MonsterFactory *mf = MonsterFactory::getInstance();
    std::unique_ptr<Monster> m = mf->randomMonster(1);
    std::cout << *m << std::endl;
    return 0;
}