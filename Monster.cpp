#include "Monster.h"
#include "Hero.h"
#include <ctime>
#include <iomanip>

Monster::Monster(std::string name, int level, int damage, int defense, int dodge)
    : Character(name, level, damage, defense, dodge)
{
}

void Monster::mainStatsUp(double percentage) {}
void Monster::subStatsUp(double percentage) {}
void Monster::displayInfo()
{

    std::cout << std::setw(25) << std::left << "Name";
    std::cout << std::setw(15) << std::left << "Level";
    std::cout << std::setw(15) << std::left << "Health";
    std::cout << std::setw(15) << std::left << "Damage";
    std::cout << std::setw(15) << std::left << "Defense";
    std::cout << std::setw(15) << std::left << "Dodge" << std::endl;
    std::cout << std::string(100, '_') << std::endl;

    std::cout << std::setw(25) << std::left << name;
    std::cout << std::setw(15) << std::left << level;
    std::cout << std::setw(15) << std::left << health;
    std::cout << std::setw(15) << std::left << damage;
    std::cout << std::setw(15) << std::left << defense;
    std::cout << std::setw(15) << std::left << dodge << std::endl;
}

void Monster::startTurn(std::unique_ptr<Hero> &opp)
{

    opp->takeDamage(damage * 0.05);
}

void Monster::takeDamage(int dmg)
{

    std::srand(std::time(nullptr));
    int random_num{};
    random_num = std::rand() % 100;

    if (random_num > dodge)
    {
        std::cout << name << " took " << dmg - (defense * 0.1) << " damage!" << std::endl;
        reduceHealth(dmg - (defense * 0.1));
    }
    else
    {
        std::cout << name << " has dodge the attack!" << std::endl;
    }
}