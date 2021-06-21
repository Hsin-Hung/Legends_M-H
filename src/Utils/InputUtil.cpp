#include "Utils/InputUtil.h"

void InputUtil::resetCin(std::istream &is, int &key)
{

    if (is.fail())
    {
        key = -1;
        is.clear();
        is.ignore();
    }
}