#ifndef _FIGHT_H_
#define _FIGHT_H_

#include <memory>
#include "Hero.h"
#include "Monster.h"

class Fight
{
private:
    std::unique_ptr<Hero> &hero;
    std::unique_ptr<Monster> &monster;

public:
    Fight(std::unique_ptr<Hero> &hero, std::unique_ptr<Monster> &monster);
    void initFight();
    void postRoundUpdate(std::unique_ptr<Hero> &hero);
    void postFightUpdate(std::unique_ptr<Hero> &hero, std::unique_ptr<Monster> &monster);
};

#endif