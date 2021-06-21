#include "Characters/HeroFactory.h"
#include "Characters/Hero.h"
#include "Characters/Warrior.h"
#include "Characters/Sorcerer.h"
#include "Characters/Paladin.h"
#include "Utils/ColoredText.h"
#include "Utils/InputUtil.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

std::string heroTypeToString(int type);

HeroFactory *HeroFactory::instance{nullptr};
std::vector<std::pair<HeroType, std::string>> HeroFactory::file_paths{std::make_pair(Warrior_T, "./data/Warriors.txt"),
                                                                      std::make_pair(Paladin_T, "./data/Paladins.txt"),
                                                                      std::make_pair(Sorcerer_T, "./data/Sorcerers.txt")};

HeroTemplate::HeroTemplate(HeroType type, std::string name, int level, int mana, int strength, int agility, int dexterity, int money, int exp)
    : type{type}, name{name}, level{level}, mana{mana}, strength{strength}, agility{agility}, dexterity{dexterity}, money{money}, exp{exp} {}

HeroFactory::HeroFactory()
{
    std::string name;
    int mana, strength, agility, dexterity, money, exp;
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
            ss >> name >> mana >> strength >> agility >> dexterity >> money >> exp;
            hero_templates.emplace_back(path.first, name, 1, mana, strength, agility, dexterity, money, exp);
            ss.clear();
        }
        in_file.close();
    }
}

HeroFactory *HeroFactory::getInstance()
{
    if (!instance)
        instance = new HeroFactory();
    return instance;
}

void HeroFactory::displayHeros()
{

    std::sort(hero_templates.begin(), hero_templates.end(), [](const HeroTemplate &lhs, const HeroTemplate &rhs)
              { return lhs.type < rhs.type; });
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left << ColoredText::white("ID");
    std::cout << std::setw(15) << std::left << "Class";
    std::cout << std::setw(25) << std::left << "Name";
    std::cout << std::setw(15) << std::left << "Mana";
    std::cout << std::setw(15) << std::left << "Strength";
    std::cout << std::setw(15) << std::left << "Agility";
    std::cout << std::setw(15) << std::left << "Dexterity";
    std::cout << std::setw(15) << std::left << "Money";
    std::cout << std::setw(15) << std::left << "Experience" << std::endl;
    std::cout << std::string(130, '_') << std::endl;

    int i{0};
    for (auto &tem : hero_templates)
    {
        std::cout << std::setw(20) << std::left << ColoredText::white(std::to_string(i));
        std::cout << std::setw(15) << std::left << heroTypeToString(tem.type);
        std::cout << std::setw(25) << std::left << tem.name;
        std::cout << std::setw(15) << std::left << tem.mana;
        std::cout << std::setw(15) << std::left << tem.strength;
        std::cout << std::setw(15) << std::left << tem.agility;
        std::cout << std::setw(15) << std::left << tem.dexterity;
        std::cout << std::setw(15) << std::left << tem.money;
        std::cout << std::setw(15) << std::left << tem.exp << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

std::unique_ptr<Hero> HeroFactory::pickHero()
{
    displayHeros();

    int id{-1};
    do
    {
        std::cout << "Pick your hero (ID): ";
        std::cin >> id;
        InputUtil::resetCin(std::cin, id);
    } while (id < 0 || (size_t)id >= hero_templates.size());

    HeroTemplate &tem = hero_templates[id];

    switch (tem.type)
    {

    case Warrior_T:
        return std::make_unique<Warrior>(tem.name, tem.mana, tem.strength, tem.agility, tem.dexterity, tem.money, tem.exp);
    case Paladin_T:
        return std::make_unique<Paladin>(tem.name, tem.mana, tem.strength, tem.agility, tem.dexterity, tem.money, tem.exp);
    case Sorcerer_T:
        return std::make_unique<Sorcerer>(tem.name, tem.mana, tem.strength, tem.agility, tem.dexterity, tem.money, tem.exp);
    default:
        std::cerr << "No such hero type ..." << std::endl;
    }
    return std::make_unique<Warrior>(tem.name, tem.mana, tem.strength, tem.agility, tem.dexterity, tem.money, tem.exp);
}

std::string heroTypeToString(int type)
{
    switch (type)
    {

    case Warrior_T:
        return "WARRIOR";
    case Paladin_T:
        return "PALADIN";
    case Sorcerer_T:
        return "SORCERER";
    default:
        std::cerr << "No such hero type ..." << std::endl;
    }

    return "N/A";
}