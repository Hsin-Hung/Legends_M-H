#include "World.h"
#include "Market.h"
#include "Common.h"
#include "Nonaccessible.h"
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
    for (auto &row : world)
    {
        std::cout << vertical_border << std::endl;
        for (auto &space : row)
        {

            std::cout << "|  "
                      << *space
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