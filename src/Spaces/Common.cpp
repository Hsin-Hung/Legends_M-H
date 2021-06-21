#include "Spaces/Common.h"
#include "Characters/Monster.h"
#include "Characters/MonsterFactory.h"
#include "Utils/Fight.h"
#include "Utils/ColoredText.h"
#include <ctime>

Common::Common() : Space(true, Common_T) {}
double Common::monsterEncounterChance{0.35};

void Common::triggerEvent(std::unique_ptr<Hero> &hero)
{
    std::srand(std::time(nullptr));
    int random_num{};
    random_num = std::rand() % 100;

    if (random_num <= monsterEncounterChance * 100)
    {

        std::unique_ptr<Monster> monster{MonsterFactory::getInstance()->randomMonster(hero->getLevel())};
        Fight fight(hero, monster);
        fight.initFight();
    }
    else
    {
        std::cout << "\n\n      " << ColoredText::red("There is no monster!") << " \n\n";
    }
}

void Common::display(std::ostream &os) const
{
    os << " ";
}

std::string Common::getSymbol() const
{
    return " ";
}