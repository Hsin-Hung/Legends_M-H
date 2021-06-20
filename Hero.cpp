#include "Hero.h"

Hero::Hero(std::string name, int mana, int strength, int agility, int dexterity, int money, int exp)
    : Character(name), mana{mana}, strength{strength}, agility{agility}, dexterity{dexterity}, money{money}, exp{exp} {}