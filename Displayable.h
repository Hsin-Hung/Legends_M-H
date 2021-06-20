#ifndef _DISPLAYABLE_H_
#define _DISPLAYABLE_H_

#include <iostream>

class Displayable
{
private:
    friend std::ostream &operator<<(std::ostream &os, const Displayable &obj);

public:
    virtual void display(std::ostream &os) const = 0;
    
};

#endif