#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Item.h"
#include "Displayable.h"
#include <vector>

class Inventory
{

private:
    int money;
    std::vector<std::unique_ptr<Item>> items;

public:
    Inventory(int money = 0);
    std::unique_ptr<Item>& getItem(size_t i);
    void removeItem(size_t i);
    void addItem(std::unique_ptr<Item>);
    bool spend(int amount);
    void earn(int amount);
    int getMoney();
    void display() const;
    void displayArmor() const;
    void displayWeapon() const;
    void displayPotion() const;
};

#endif