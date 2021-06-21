#include "Utils/Fight.h"
#include "Utils/ColoredText.h"
#include <limits>

Fight::Fight(std::unique_ptr<Hero> &hero, std::unique_ptr<Monster> &monster) : hero{hero}, monster{monster} {};

void Fight::initFight()
{

    int turn{1};
    char buf;

    std::cout << "\n      "
              << "You have encountered " << *monster << std::endl;
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
            hero->mainStatsUp(0.1);
            hero->displayStats();
            monster->displayInfo();
            std::cout << "Enter any key to continue: \n";
            std::cin.get(buf);
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
            }
        }
        turn = (turn + 1) % 2;

    } while (hero->isAlive() && monster->isAlive());

    if (hero->isAlive())
    {
        std::cout << "\n\n      " << ColoredText::green("YOU WIN !") << std::endl;
        hero->winFight(monster);
    }
    else
    {
        std::cout << "\n\n      " << ColoredText::red("YOU LOST !") << std::endl;
        hero->lostFight();
    }
    std::cout << "Enter any key to continue: \n";
    std::cin.get(buf);
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
    }
}