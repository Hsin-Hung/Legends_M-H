#include "Spaces/Market.h"
#include "Items/Armor.h"
#include "Items/Potion.h"
#include "Items/Weapon.h"
#include "Utils/ColoredText.h"
#include "Utils/InputUtil.h"
#include <ostream>
#include <fstream>
#include <sstream>

ItemTemplate::ItemTemplate(ItemType type, std::string name, int cost, int required_lvl, int damage, int damage_reduced, int attr_inc, Attribute attr_aff)
    : type{type}, name{name}, cost{cost}, required_lvl{required_lvl}, damage{damage}, damage_reduced{damage_reduced}, attr_inc{attr_inc}, attr_aff{attr_aff}
{
}

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
                items.emplace_back(std::make_unique<Potion>(name, cost, required_lvl, attr_inc, static_cast<Attribute>(attr_aff)));
            }
            else if (path.first == Armor_T)
            {
                ss >> name >> cost >> required_lvl >> damage_reduction;
                items.emplace_back(std::make_unique<Armor>(name, cost, required_lvl, damage_reduction));
            }
            else if (path.first == Weapon_T)
            {
                ss >> name >> cost >> required_lvl >> damage;
                items.emplace_back(std::make_unique<Weapon>(name, cost, required_lvl, damage));
            }
            else
            {
                std::cerr << "No such Item type ..." << std::endl;
                exit(1);
            }
            item_templates.emplace_back(path.first, name, cost, required_lvl, damage, damage_reduction, attr_inc, static_cast<Attribute>(attr_aff));
            ss.clear();
        }
        in_file.close();
    }
}

void Market::enterMarket(std::unique_ptr<Hero> &hero)
{

    std::cout << "\n\n      " << ColoredText::yellow("-WELCOME TO THE MARKET-") << " \n\n";
    int choice{-1};

    while (1)
    {

        do
        {
            std::cout << "1.Armory 2.Weaponry 3.Potion 4.Exit (enter ID): ";
            std::cin >> choice;
            InputUtil::resetCin(std::cin, choice);
        } while (choice < 1 || choice > 4);

        if (choice == 4)
            return;

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

        for (auto i{0}; i < items.size(); i++)
        {
            if (items[i]->getType() == choiceType)
            {
                std::cout << std::setw(5) << std::left << i;
                std::cout << *items[i];
            }
        }
        int itemChoice{-1};
        do
        {
            std::cout << "\nBuy an item (enter ID): ";
            std::cin >> itemChoice;
            InputUtil::resetCin(std::cin, itemChoice);
        } while (itemChoice < 0 || (size_t)itemChoice >= item_templates.size() || item_templates[itemChoice].type != choiceType);

        ItemTemplate &tem{item_templates[itemChoice]};
        if (choiceType == Armor_T)
        {
            hero->buyItem(std::make_unique<Armor>(tem.name, tem.cost, tem.required_lvl, tem.damage_reduced));
        }
        else if (choiceType == Weapon_T)
        {
            hero->buyItem(std::make_unique<Weapon>(tem.name, tem.cost, tem.required_lvl, tem.damage));
        }
        else if (choiceType == Potion_T)
        {
            hero->buyItem(std::make_unique<Potion>(tem.name, tem.cost, tem.required_lvl, tem.attr_inc, tem.attr_aff));
        }
    }
}

void Market::triggerEvent(std::unique_ptr<Hero> &hero)
{
    enterMarket(hero);
}

void Market::display(std::ostream &os) const
{
    os << ColoredText::yellow("M");
}

std::string Market::getSymbol() const
{
    return ColoredText::yellow("M");
}