#ifndef _HERO_FACTORY_H_
#define _HERO_FACTORY_H_

#include <vector>
#include <string>
#include <memory>
#include "Characters/Hero.h"

enum HeroType
{
    Warrior_T,
    Paladin_T,
    Sorcerer_T
};

struct HeroTemplate
{
    HeroType type;
    std::string name;
    int level{};
    int mana{};
    int strength{};
    int agility{};
    int dexterity{};
    int money{};
    int exp{};
    HeroTemplate(HeroType, std::string, int, int, int, int, int, int, int);
};

class HeroFactory
{

private:
    static HeroFactory *instance;
    static std::vector<std::pair<HeroType, std::string>> file_paths;
    std::vector<HeroTemplate> hero_templates;
    HeroFactory();
    void displayHeros();

public:
    static HeroFactory *getInstance();
    ~HeroFactory() = default;
    std::unique_ptr<Hero> pickHero();
};

#endif