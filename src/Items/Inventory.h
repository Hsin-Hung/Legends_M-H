#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "Items/Weapon.h"
#include "Items/Armor.h"
#include "Items/Potion.h"
#include "Items/Item.h"
#include "Utils/Displayable.h"
#include <vector>

class Inventory
{

private:
    int money;
    std::vector<std::unique_ptr<Item>> items;

public:
    Inventory(int money = 0);
    std::unique_ptr<Item> &getItem(size_t i);
    void removeItem(size_t i);
    void addItem(std::unique_ptr<Item>);
    bool spend(int amount);
    void earn(int amount);
    int getMoney() const;
    void display() const;
    bool displayArmor() const;
    bool displayWeapon() const;
    bool displayPotion() const;
    bool isValidIndex(int i) const;
};

#endif