#include "HeroFactory.h"

HeroFactory *HeroFactory::instance{nullptr};
std::vector<std::pair<HeroType, std::string>> HeroFactory::file_paths{std::make_pair(Warrior_T, "./data/Warriors.txt"),
                                                                            std::make_pair(Paladin_T, "./data/Paladins.txt"),
                                                                            std::make_pair(Sorcerer_T, "./data/Sorcerers.txt")};