#include "Characters/MonsterFactory.h"
#include "Characters/Dragon.h"
#include "Characters/Exoskeleton.h"
#include "Characters/Spirit.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>

MonsterFactory *MonsterFactory::instance{nullptr};
std::vector<std::pair<MonsterType, std::string>> MonsterFactory::file_paths{std::make_pair(Dragon_T, "./data/Dragons.txt"),
                                                                            std::make_pair(Exoskeleton_T, "./data/Exoskeletons.txt"),
                                                                            std::make_pair(Spirit_T, "./data/Spirits.txt")};

MonsterTemplate::MonsterTemplate(MonsterType type, std::string name, int level, int damage, int defense, int dodge)
    : type{type}, name{name}, level{level}, damage{damage}, defense{defense}, dodge{dodge} {}

MonsterFactory::MonsterFactory()
{
    std::string name;
    int level, damage, defense, dodge;
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
            ss >> name >> level >> damage >> defense >> dodge;
            monster_templates.emplace_back(path.first, name, level, damage, defense, dodge);
            ss.clear();
        }
        in_file.close();
    }
}

MonsterFactory *MonsterFactory::getInstance()
{
    if (!instance)
        instance = new MonsterFactory();
    return instance;
}

std::unique_ptr<Monster> MonsterFactory::randomMonster(int level)
{
    std::random_device rd;
    auto rng = std::default_random_engine{rd()};
    std::shuffle(monster_templates.begin(), monster_templates.end(), rng);

    for (auto &tem : monster_templates)
    {
        if (tem.level == level)
        {
            switch (tem.type)
            {

            case Dragon_T:
                return std::make_unique<Dragon>(tem.name, tem.level, tem.damage, tem.defense, tem.dodge);
            case Exoskeleton_T:
                return std::make_unique<Exoskeleton>(tem.name, tem.level, tem.damage, tem.defense, tem.dodge);
            case Spirit_T:
                return std::make_unique<Spirit>(tem.name, tem.level, tem.damage, tem.defense, tem.dodge);
            default:
                std::cerr << "Invalid monster type ..." << std::endl;
            }
        }
    }
    return std::make_unique<Exoskeleton>("BigBad-Wolfy", level, 100 * level, 100 * level, 20);
}