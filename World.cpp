#include "World.h"
#include "Market.h"
#include "Common.h"
#include "Nonaccessible.h"
#include "HeroFactory.h"
#include "MonsterFactory.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <memory>

double World::nonAccessible{0.2};
double World::market{0.2};
double World::common{0.6};

World::World(int dim) : dim{dim}
{
    generateWorld();
}

void World::displayWorld()
{

    std::string vertical_border, horizontal_border;
    for (int i = 0; i < dim; i++)
    {
        vertical_border += "|     ";
        horizontal_border += "------";
    }
    vertical_border += "|";
    horizontal_border += "-";

    std::cout << horizontal_border << std::endl;
    for (int r = 0; r < world.size(); r++)
    {
        std::cout << vertical_border << std::endl;
        for (int c = 0; c < world[r].size(); c++)
        {

            std::cout << "| ";
            if (r == hero_coord.first && c == hero_coord.second)
            {
                std::cout << "H";
            }
            else
            {
                std::cout << " ";
            }

            std::cout << *world[r][c]
                      << "  ";
        }
        std::cout << "|" << std::endl;
        std::cout << vertical_border << std::endl;
        std::cout << horizontal_border << std::endl;
    }
}

void World::displayControl()
{
    std::cout << "W/w: move up\n";
    std::cout << "A/a: move left\n";
    std::cout << "S/s: move down\n";
    std::cout << "D/d: move right\n";
    std::cout << "Q/q: quit game\n";
    std::cout << "I/i: show information\n";
    std::cout << "Enter a move: ";
}

void World::generateWorld()
{

    std::srand(std::time(nullptr));
    int random_num{};
    for (auto r = 0; r < dim; r++)
    {
        std::vector<std::unique_ptr<Space>> row;
        for (auto c = 0; c < dim; c++)
        {
            random_num = std::rand() % 100;
            if (random_num < nonAccessible * 100)
            {
                row.emplace_back(std::make_unique<Nonaccessible>());
            }
            else if (random_num >= 100 - market * 100)
            {
                row.emplace_back(std::make_unique<Market>());
            }
            else
            {
                row.emplace_back(std::make_unique<Common>());
            }
        }
        world.push_back(std::move(row));
    }
}

void World::initHero()
{

    HeroFactory *h = HeroFactory::getInstance();
    hero = std::move(h->pickHero());

    for (int r = 0; r < world.size(); r++)
    {
        for (int c = 0; c < world[r].size(); c++)
        {
            if (world[r][c]->getType() == Common_T)
            {
                hero_coord = std::make_pair(r, c);
                return;
            }
        }
    }
}

bool World::validCoord(int x, int y)
{

    return x >= 0 && x < dim && y >= 0 && y < dim;
}

void World::doMove(char move)
{

    int x{-1}, y{-1};
    switch (move)
    {

    case 'W':
        x = hero_coord.first - 1;
        y = hero_coord.second;
        break;
    case 'A':
        x = hero_coord.first;
        y = hero_coord.second - 1;
        break;
    case 'S':
        x = hero_coord.first + 1;
        y = hero_coord.second;
        break;
    case 'D':
        x = hero_coord.first;
        y = hero_coord.second + 1;
        break;
    case 'I':
        hero->displayInfo();
        break;
    default:
        std::cout << "Invalid move! Enter Again!" << std::endl;
    }

    if (validCoord(x, y))
    {
        if (world[x][y]->isAccessible())
        {
            hero_coord.first = x;
            hero_coord.second = y;
            world[x][y]->triggerEvent(hero);
        }
    }
}

void World::initWorld()
{
    initHero();

    char move;

    do
    {
        displayWorld();
        displayControl();
        std::cin >> move;
        move = std::toupper(move);
        doMove(move);
        std::cin.clear();
        std::cin.ignore();
    } while (move != 'Q');
}