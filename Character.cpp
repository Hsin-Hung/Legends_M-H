
#include "Character.h"

Character::Character(std::string name, int level, int damage, int defense, int dodge)
    : name{name}, level{level}, damage{damage}, defense{defense}, dodge{dodge}
{
    health = level * 100;
}

bool Character::isAlive()
{
    return health > 0;
}

void Character::reduceHealth(int dmg)
{
    if (dmg > 0)
    {
        health -= dmg;
        if (health <= 0)
        {
            std::cout << name << " are dead!" << std::endl;
            health = 0;
        }
    }
}

int Character::getHealth()
{
    return health;
}
void Character::gainHealth(int amount)
{
    health += amount;
    if (health > level * 100)
        health = level * 100;
}

int Character::getLevel()
{
    return level;
}