#include "Weapon.h"
#include <iomanip>
#include "Hero.h"
Weapon::Weapon(std::string name, int cost, int required_lvl, int damage)
    : Item(Weapon_T, name, cost, required_lvl), damage{damage}
{
}

void Weapon::display(std::ostream &os) const
{
    os << std::setw(25) << std::left << name;
    os << std::setw(15) << std::left << cost;
    os << std::setw(15) << std::left << required_lvl;
    os << std::setw(15) << std::left << damage << std::endl;
}

void Weapon::displayHeader()
{
    std::cout << std::setw(5) << std::left << "ID";
    std::cout << std::setw(25) << std::left << "Name";
    std::cout << std::setw(15) << std::left << "Cost";
    std::cout << std::setw(15) << std::left << "Required_lvl";
    std::cout << std::setw(15) << std::left << "Damage" << std::endl;
    std::cout << std::string(100, '_') << std::endl;
}

void Weapon::updateHero(Hero &hero) const
{
    hero.increaseDamage(damage);
}
