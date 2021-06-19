#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

class Character{
    private:
        std::string name;
        int mana;
        int level;
        int damage;
        double dodge;
    public:
        Character();

};

#endif