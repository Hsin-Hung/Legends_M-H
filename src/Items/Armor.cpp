#include <iostream>
#include <iomanip>
#include "Items/Armor.h"
#include "Characters/Hero.h"

Armor::Armor(std::string name, int cost, int required_lvl, int damage_reduction)
    : Item(Armor_T, name, cost, required_lvl), damage_reduction{damage_reduction}
{
}

void Armor::displayHeader()
{
    std::cout << std::setw(5) << std::left << "ID";
    std::cout << std::setw(25) << std::left << "Name";
    std::cout << std::setw(15) << std::left << "Cost";
    std::cout << std::setw(15) << std::left << "Required_lvl";
    std::cout << std::setw(15) << std::left << "Damage_reduction" << std::endl;
    std::cout << std::string(100, '_') << std::endl;
}

void Armor::display(std::ostream &os) const
{
    os << std::setw(25) << std::left << name;
    os << std::setw(15) << std::left << cost;
    os << std::setw(15) << std::left << required_lvl;
    os << std::setw(15) << std::left << damage_reduction << std::endl;
}

void Armor::useItem(Hero &hero) const
{
    hero.gainDamageReduction(damage_reduction);
}