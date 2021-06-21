#include "Fight.h"

Fight::Fight(std::unique_ptr<Hero> &hero, std::unique_ptr<Monster> &monster) : hero{hero}, monster{monster} {};

void Fight::initFight()
{

    int turn{1};
    std::cout << "You have encountered " << *monster << std::endl;
    monster->displayInfo();
    do
    {
        if (turn)
        {
            hero->startTurn(monster);
        }
        else
        {
            monster->startTurn(hero);
            postRoundUpdate(hero);
            hero->displayStats();
            monster->displayInfo();
        }
        turn = (turn + 1) % 2;

    } while (hero->isAlive() && monster->isAlive());

    if (hero->isAlive())
    {
        std::cout << "YOU WIN THE FIGHT!" << std::endl;
        postFightUpdate(hero, monster);
    }
    else
    {
        std::cout << "YOU LOST THE FIGHT!" << std::endl;
    }
}

void Fight::postRoundUpdate(std::unique_ptr<Hero> &hero)
{
    hero->mainStatsUp(0.1);
}
void Fight::postFightUpdate(std::unique_ptr<Hero> &hero, std::unique_ptr<Monster> &monster)
{
    hero->winFight(monster);
}