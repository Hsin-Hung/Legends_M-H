#include "Characters/Character.h"
#include "Utils/ColoredText.h"
#include <algorithm>

Character::Character(std::string name, int level, int damage, int defense, int dodge)
    : name{name}, level{level}, damage{damage}, defense{defense}, dodge{dodge}
{
    health = level * 100;
}

bool Character::isAlive() const
{
    return health > 0;
}
void Character::gainDamage(int amount)
{
    damage += amount;
    if (damage < 0)
        damage = 0;
}

void Character::gainDamageReduction(int amount)
{
    defense += amount;
    if (defense < 0)
        defense = 0;
}
void Character::reduceHealth(int dmg)
{
    if (dmg > 0)
    {

        health = std::max(0, health - dmg);
        if (health == 0)
            std::cout << ColoredText::red(name + " is dead!") << std::endl;
    }
}

int Character::getHealth() const
{
    return health;
}
void Character::gainHealth(int amount)
{
    health = std::min(health + amount, level * 100);
}

int Character::getLevel() const
{
    return level;
}