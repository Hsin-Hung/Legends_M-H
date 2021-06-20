#ifndef _WORLD_H_
#define _WORLD_H_

#include "Space.h"
#include "Hero.h"
#include <vector>
#include <memory>

class World
{

private:
    static double nonAccessible, market, common;
    int dim;
    std::unique_ptr<Hero> hero;
    std::pair<int, int> hero_coord;
    std::vector<std::vector<std::unique_ptr<Space>>> world;
    void generateWorld();
    void initHero();
    bool validCoord(int x, int y);
    void displayWorld();
    void displayControl();
    void doMove(char move);

public:
    World(int dim);
    void initWorld();
};

#endif