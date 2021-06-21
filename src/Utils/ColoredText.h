#ifndef _COLORED_TEXT_H_
#define _COLORED_TEXT_H_

#include <string>

struct ColoredText
{
    static std::string white(std::string text);
    static std::string red(std::string text);
    static std::string yellow(std::string text);
    static std::string green(std::string text);
};

#endif