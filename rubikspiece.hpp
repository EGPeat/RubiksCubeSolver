#ifndef RUBIKSPIECE_HPP
#define RUBIKSPIECE_HPP
#include <map>
#include <string>
#include <vector>

enum class Color {
    White,
    Red,
    Blue,
    Yellow,
    Orange,
    Green
};

enum EdgeType {Edge, Corner, Center};

std::map<Color, std::string> colorMap = {
    { Color::White, "\U00002B1C " },
    //{ Color::White, "\U0001F7E5" }, //brown
    { Color::Red, "\U0001F7E5" },
    { Color::Blue, "\U0001F7E6" },
    { Color::Yellow, "\U0001F7E8" },
    { Color::Orange, "\U0001F7E7" },
    { Color::Green, "\U0001F7E9" }
};


class RubiksPiece //if i dont make seperate for edge and corner, i need to add in something to let it tell apart and neighbors
{

public:
    EdgeType _edgeType;
    std::string _emoji;
    Color _color;
    std::vector<Color> _connectedColors; //this should be private idk



};








#endif