#include "Common.h"
#include "Monster.h"
#include "MonsterFactory.h"
#include "Fight.h"
#include <ctime>

Common::Common() : Space(true, Common_T) {}
double Common::monsterEncounterChance{0.3};

void Common::triggerEvent(std::unique_ptr<Hero> &hero)
{
    std::srand(std::time(nullptr));
    int random_num{};
    random_num = std::rand() % 100;

    if (random_num <= monsterEncounterChance * 100)
    {
        std::cout << "You have encountered a monster!" << std::endl;
        std::unique_ptr<Monster> monster{MonsterFactory::getInstance()->randomMonster(hero->getLevel())};
        Fight fight(hero, monster);
        fight.initFight();
        }
    else
    {
        std::cout << "There is no monster!" << std::endl;
    }
}

void Common::display(std::ostream &os) const
{
    os << " ";
}