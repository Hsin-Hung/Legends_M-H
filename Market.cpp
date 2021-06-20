#include "Market.h"
#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"
#include <ostream>
#include <fstream>
#include <sstream>

std::vector<std::pair<ItemType, std::string>> Market::file_paths{
    std::make_pair(Armor_T, "./data/Armory.txt"),
    std::make_pair(Weapon_T, "./data/Weaponry.txt"),
    std::make_pair(Potion_T, "./data/Potions.txt")};

Market::Market() : Space(true, Market_T)
{

    std::string name;
    int cost{}, required_lvl{}, damage{}, damage_reduction{}, attr_inc{}, attr_aff{};
    std::ifstream in_file;
    std::stringstream ss;

    for (auto &path : file_paths)
    {
        in_file.open(path.second);
        if (!in_file)
        {
            std::cerr << "Failed to open file ..." << std::endl;
            exit(1);
        }

        std::string line;
        getline(in_file, line);
        while (getline(in_file, line))
        {
            ss << line;
            if (path.first == Potion_T)
            {
                ss >> name >> cost >> required_lvl >> attr_inc >> attr_aff;
                items.emplace_back(std::make_shared<Potion>(name, cost, required_lvl, attr_inc, static_cast<Attribute>(attr_aff)));
            }
            else if (path.first == Armor_T)
            {
                ss >> name >> cost >> required_lvl >> damage_reduction;
                items.emplace_back(std::make_shared<Armor>(name, cost, required_lvl, damage_reduction));
            }
            else if (path.first == Weapon_T)
            {
                ss >> name >> cost >> required_lvl >> damage;
                items.emplace_back(std::make_shared<Weapon>(name, cost, required_lvl, damage));
            }
            ss.clear();
        }
        in_file.close();
    }

    enterMarket();
}

int Market::enterMarket()
{
    int choice{-1};
    std::cout << "Buy 1.Armory  2.Weaponry  3.Potion (enter number) 4.Exit: ";
    do
    {
        std::cin >> choice;
    } while (std::cin.fail() || choice < 1 || choice > 3);

    if (choice == 4)
        return -1;

    ItemType choiceType{static_cast<ItemType>(choice)};
    if (choiceType == Armor_T)
    {
        Armor::displayHeader();
    }
    else if (choiceType == Weapon_T)
    {
        Weapon::displayHeader();
    }
    else if (choiceType == Potion_T)
    {
        Potion::displayHeader();
    }

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getType() == choiceType)
        {
            std::cout << std::setw(5) << std::left << i;
            std::cout << *items[i];
        }
    }

    return choice;
}

void Market::triggerEvent(std::unique_ptr<Hero> &hero)
{
    std::cout << "      WELCOME TO THE MARKET\n"
              << std::endl;

    int choice = enterMarket();
}

void Market::display(std::ostream &os) const
{
    os << "M";
}