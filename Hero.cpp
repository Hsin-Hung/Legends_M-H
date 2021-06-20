#include "Hero.h"

Hero::Hero(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Character(name), mana{mana}, strength{strength}, agility{agility}, dexterity{dexterity}, money{money}, exp{exp} {}

bool Hero::buyItem(std::shared_ptr<Item> &item)
{
    if (item->getCost() <= money && item->getRequiredLvl() <= level)
    {
        money-=item->getCost();
        
        return true;
    }

    return false;
}