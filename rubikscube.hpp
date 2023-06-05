#ifndef RUBIKSCUBE_HPP
#define RUBIKSCUBE_HPP
#include <iostream>
#include <array>
#include <string>
#include <map>
enum class Move {
    Right=0,
    RightPr=1,
    Left=2,
    LeftPr=3,
    Up=4,
    UpPr=5,
    Down=6,
    DownPr=7,
    Front=8,
    FrontP=9,
    Back=10,
    BackPr=11,
    rotateZ=12,
    rotateZPr=13,
    rotateY=14,
    rotateYPr=15,
    rotateX=16,
    rotateXPr=17
};
enum class Color {
    White,
    Red,
    Blue,
    Yellow,
    Orange,
    Green
};

std::map<Color, std::string> colorMap = {
    { Color::White, "\U00002B1C " },
    //{ Color::White, "\U0001F7E5" }, //brown
    { Color::Red, "\U0001F7E5" },
    { Color::Blue, "\U0001F7E6" },
    { Color::Yellow, "\U0001F7E8" },
    { Color::Orange, "\U0001F7E7" },
    { Color::Green, "\U0001F7E9" }
};
class rCube
{
    private:

    //yArray is read top to bottom. From leftmost of white cube (counter clockwise)
    //xArray is read left to right. From bottommost of white cube (clockwise)
    //zArray is read back to front. From leftmost of blue cube (clockwise)
    std::array<std::array<std::string, 12>, 3> yArray;
  //  std::array<std::array<std::string, 12>, 3> xArray;
    std::array<std::array<std::string, 12>, 3> zArray;
    
    public:
    std::array<std::array<std::string, 12>, 3> xArray;
    void debugprintCube();
    rCube();
    //import from File
    void messUp(int numMoves,int snapShot);
    void printCube();
    void movement(Move moveChoice);
    //distanceChoice is in mult of 3
    void yMovement(int layerChoice, int distanceChoice);//need to work around stuff to rotate
    void xMovement(int layerChoice, int distanceChoice);
 //   void zMovement(int layerChoice, int distanceChoice);

};



#endif