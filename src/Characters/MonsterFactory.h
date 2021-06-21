#ifndef _MONSTER_FACTORY_H_
#define _MONSTER_FACTORY_H_

#include "Characters/Monster.h"
#include <string>
#include <memory>
#include <vector>

enum MonsterType
{
    Dragon_T,
    Exoskeleton_T,
    Spirit_T
};

struct MonsterTemplate
{
    MonsterType type;
    std::string name;
    int level{};
    int damage{};
    int defense{};
    int dodge{};
    MonsterTemplate(MonsterType, std::string, int, int, int, int);
};

class MonsterFactory
{

private:
    static MonsterFactory *instance;
    static std::vector<std::pair<MonsterType, std::string>> file_paths;
    std::vector<MonsterTemplate> monster_templates;
    MonsterFactory();

public:
    static MonsterFactory *getInstance();
    ~MonsterFactory() = default;
    std::unique_ptr<Monster> randomMonster(int level);
};

#endif