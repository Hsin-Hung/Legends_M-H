#include "Item.h"

Item::Item(ItemType type, std::string name, int cost, int required_lvl) : type{type}, name{name}, cost{cost}, required_lvl{required_lvl} {}

ItemType Item::getType() { return type; };

std::string Item::getName() { return name; };