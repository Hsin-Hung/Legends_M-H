#include "Potion.h"
#include <iomanip>

void Potion::display(std::ostream &os) const
{
    os << std::setw(25) << std::left << name;
    os << std::setw(15) << std::left << cost;
    os << std::setw(20) << std::left << required_lvl;
    os << std::setw(25) << std::left << attr_inc;
    os << std::setw(25) << std::left << attrAffToString(attr_aff) << std::endl;
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
    }

    return "";
}

Potion::Potion(std::string name, int cost, int required_lvl, int attr_inc, Attribute attr_aff)
    : Item(Potion_T, name, cost, required_lvl), attr_inc{attr_inc}, attr_aff{attr_aff}
{
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