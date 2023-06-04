#ifndef RUBIKSCUBE_HPP
#define RUBIKSCUBE_HPP
#include <iostream>
#include <array>
#include <string>
#include <map>
enum class Color {
    Brown,
    Red,
    Blue,
    Yellow,
    Orange,
    Green
};

std::map<Color, std::string> colorMap = {
    { Color::Brown, "\U0001F7EB" },
    { Color::Red, "\U0001F7E5" },
    { Color::Blue, "\U0001F7E6" },
    { Color::Yellow, "\U0001F7E8" },
    { Color::Orange, "\U0001F7E7" },
    { Color::Green, "\U0001F7E9" }
};
class rCube
{
    private:
    std::array<std::array<std::string, 12>, 3> yArray;
    std::array<std::array<std::string, 12>, 3> xArray;
    std::array<std::array<std::string, 12>, 3> zArray;
    
    public:
    rCube();
    //import from File
    //void messUp();
    

};



#endif