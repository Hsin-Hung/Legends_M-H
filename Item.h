
#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>

class Item
{

private:
    std::string name;
    int cost;
    int required_lvl;

public:
    Item(std::string name, int cost, int required_lvl);
};
#endif