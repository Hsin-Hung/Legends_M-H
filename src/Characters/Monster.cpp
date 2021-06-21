#include "Characters/Monster.h"
#include "Characters/Hero.h"
#include "Utils/ColoredText.h"
#include <ctime>
#include <iomanip>

Monster::Monster(std::string name, int level, int damage, int defense, int dodge)
    : Character(name, level, damage, defense, dodge)
{
}

void Monster::mainStatsUp(double percentage)
{
    health *= (1.0 + percentage);
}
void Monster::subStatsUp(double percentage)
{
    damage *= (1.0 + percentage);
    defense *= (1.0 + percentage);
    dodge *= (1.0 + percentage);
}
void Monster::displayInfo()
{
    std::cout << std::endl;
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
    std::cout << std::endl;
}

void Monster::startTurn(std::unique_ptr<Hero> &opp)
{

    std::cout << ColoredText::red("       MONSTER'S TURN!\n") << std::endl;
    opp->takeDamage(damage * 0.2);
}

void Monster::takeDamage(int dmg)
{

    std::srand(std::time(nullptr));
    int random_num{};
    random_num = std::rand() % 100;

    if (random_num > dodge)
    {
        std::cout << std::endl;
        std::cout << ColoredText::red(name) << " took " << ColoredText::red(std::to_string(dmg - (defense * 0.1))) << " damage!\n"
                  << std::endl;
        reduceHealth(dmg - (defense * 0.05));
    }
    else
    {
        std::cout << ColoredText::red(name) << " has dodge the attack!" << std::endl;
    }
}