#ifndef _WORLD_H_
#define _WORLD_H_

#include "Space.h"
#include <vector>
#include <memory>

class World
{

private:
    static double nonAccessible, market, common;
    int dim;
    std::vector<std::vector<std::unique_ptr<Space>>> world;
    void generateWorld();
public:
    World(int dim);
    void displayWorld();
    void displayControl();
    
};

#endif