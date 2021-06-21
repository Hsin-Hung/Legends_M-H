#include "Items/Potion.h"
#include "Characters/Hero.h"
#include <iomanip>

Potion::Potion(std::string name, int cost, int required_lvl, int attr_inc, Attribute attr_aff)
    : Item(Potion_T, name, cost, required_lvl), attr_inc{attr_inc}, attr_aff{attr_aff}
{
}

std::string Potion::attrAffToString(const Attribute attr)
{

    switch (attr)
    {

    case health:
        return "Health";
    case strength:
        return "Strength";
    case mana:
        return "Mana";
    case agility:
        return "Agility";
    case dexterity:
        return "Dexterity";
    case defense:
        return "Defense";
    default:
        std::cerr << "No such attribute ..." << std::endl;
        exit(1);
    }

    return "";
}

void Potion::displayHeader()
{
    std::cout << std::setw(5) << std::left << "ID";
    std::cout << std::setw(25) << std::left << "Name";
    std::cout << std::setw(15) << std::left << "Cost";
    std::cout << std::setw(20) << std::left << "Required_lvl";
    std::cout << std::setw(25) << std::left << "Attribute_increase";
    std::cout << std::setw(25) << std::left << "Attribute_affected" << std::endl;
    std::cout << std::string(150, '_') << std::endl;
}

void Potion::display(std::ostream &os) const
{
    os << std::setw(25) << std::left << name;
    os << std::setw(15) << std::left << cost;
    os << std::setw(20) << std::left << required_lvl;
    os << std::setw(25) << std::left << attr_inc;
    os << std::setw(25) << std::left << attrAffToString(attr_aff) << std::endl;
}

void Potion::useItem(Hero &hero) const
{
    switch (attr_aff)
    {

    case health:
        hero.gainHealth(attr_inc);
        break;
    case strength:
        hero.gainStrength(attr_inc);
        break;
    case mana:
        hero.gainMana(attr_inc);
        break;
    case agility:
        hero.gainAgility(attr_inc);
        break;
    case dexterity:
        hero.gainDexterity(attr_inc);
        break;
    case defense:
        hero.gainDamageReduction(attr_inc);
        break;
    default:
        std::cerr << "No such attribute ..." << std::endl;
        exit(1);
    }
}