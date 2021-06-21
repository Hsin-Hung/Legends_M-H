#include "Utils/ColoredText.h"

std::string ColoredText::red(std::string text)
{

    return "\033[1;31m" + text + "\033[0m";
}
std::string ColoredText::yellow(std::string text)
{

    return "\033[1;33m" + text + "\033[0m";
}

std::string ColoredText::green(std::string text)
{

    return "\033[1;32m" + text + "\033[0m";
}

std::string ColoredText::white(std::string text)
{
    return "\033[1;37m" + text + "\033[0m";
}