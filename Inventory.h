#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include <vector>

class Inventory
{

private:
    std::vector<Weapon> weapons;
    std::vector<Armor> armors;
    std::vector<Potion> potions;

public:
    Inventory() = default;
    
};

#endif