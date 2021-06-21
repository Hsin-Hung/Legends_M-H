#include "Spaces/World.h"
#include "Spaces/Market.h"
#include "Spaces/Common.h"
#include "Spaces/Nonaccessible.h"
#include "Characters/HeroFactory.h"
#include "Characters/MonsterFactory.h"
#include "Utils/ColoredText.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <memory>

double World::nonAccessiblePct{0.2};
double World::marketPct{0.1};
double World::commonPct{0.7};

World::World(int dim) : dim{dim}
{
}

void World::displayWorld()
{

    std::string vertical_border, horizontal_border, map;
    for (auto i{0}; i < dim; i++)
    {
        vertical_border += "|     ";
        horizontal_border += "------";
    }
    vertical_border += "|\n";
    horizontal_border += "-\n";

    std::cout << std::endl;
    map += ColoredText::green("H") + ":You " + ColoredText::yellow("M") + ":Market " + ColoredText::white("X") + ":Inaccessible\n";
    map += horizontal_border;
    for (auto r{0}; r < world.size(); r++)
    {
        map += vertical_border;
        for (auto c{0}; c < world[r].size(); c++)
        {
            map += "| ";
            if (r == hero_coord.first && c == hero_coord.second)
            {
                map += ColoredText::green("H");
            }
            else
            {
                map += " ";
            }

            map += world[r][c]->getSymbol() + "  ";
        }
        map += "|\n";
        map += vertical_border;
        map += horizontal_border;
    }

    std::cout << map << std::endl;
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
    for (auto r{0}; r < dim; r++)
    {
        std::vector<std::unique_ptr<Space>> row;
        for (auto c{0}; c < dim; c++)
        {
            random_num = std::rand() % 100;
            if (random_num < nonAccessiblePct * 100)
            {
                row.emplace_back(std::make_unique<Nonaccessible>());
            }
            else if (random_num >= 100 - marketPct * 100)
            {
                row.emplace_back(std::make_unique<Market>());
            }
            else
            {
                row.emplace_back(std::make_unique<Common>());
            }
        }
        world.emplace_back(std::move(row));
    }
}

void World::initHero()
{

    HeroFactory *h = HeroFactory::getInstance();
    hero = std::move(h->pickHero());

    for (auto r{0}; r < world.size(); r++)
    {
        for (auto c{0}; c < world[r].size(); c++)
        {
            if (world[r][c]->getType() == Common_T)
            {
                hero_coord = std::make_pair(r, c);
                return;
            }
        }
    }
}

bool World::isValidCoord(const int &x, const int &y) const
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

    if (isValidCoord(x, y) && world[x][y]->isAccessible())
    {

        hero_coord.first = x;
        hero_coord.second = y;
        world[x][y]->triggerEvent(hero);
    }
}

void World::initWorld()
{
    generateWorld();
    initHero();

    char move;

    do
    {
        displayWorld();
        displayControl();
        std::cin >> move;
        move = std::toupper(move);
        doMove(move);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
    } while (move != 'Q');
}