#ifndef RUBIKSCUBE_HPP
#define RUBIKSCUBE_HPP
#include <iostream>
#include <array>
#include <string>
#include <map>
#include "rubikspiece.hpp"
enum class Move {
    Right=0,
    RightPr=1,
    Left=2,//have to think really hard about the inputs on these types due to how it's coded
    LeftPr=3,
    Top=4,
    TopPr=5,
    Bottom=6,
    BottomPr=7,
    Front=8,
    FrontPr=9,
    Back=10,
    BackPr=11,
    rotateZ=12,
    rotateZPr=13,
    rotateY=14,
    rotateYPr=15,
    rotateX=16,
    rotateXPr=17
};




class rCube
{
    private:

    //yArray is read top to bottom. From leftmost of white cube (counter clockwise)
    //xArray is read left to right. From bottommost of white cube (clockwise)
    //zArray is read back to front. From leftmost of blue cube (clockwise)
    std::array<std::array<RubiksPiece, 3>, 3> topFace; //blue
    std::array<std::array<RubiksPiece, 3>, 3> bottomFace;//green
    std::array<std::array<RubiksPiece, 3>, 3> firstFace;//white
    std::array<std::array<RubiksPiece, 3>, 3> secondFace;//red
    std::array<std::array<RubiksPiece, 3>, 3> thirdFace;//yellow
    std::array<std::array<RubiksPiece, 3>, 3> fourthFace;//orange
    
    public:
    
    
    rCube();
    std::array<std::array<RubiksPiece, 3>, 3> setupEdgeType(std::array<std::array<RubiksPiece, 3>, 3> face);
    //import from File
    //void messUp(int numMoves,int snapShot);
    void printCube();
    void printCubeCross();
   // void movement(Move moveChoice);
    //distanceChoice is in mult of 3
   // void yMovement(int layerChoice, int distanceChoice);//need to work around stuff to rotate
   // void xMovement(int layerChoice, int distanceChoice);
   // void zMovement(int layerChoice, int distanceChoice); //ADD FACE ROTATION
 //std::array<std::array<std::string, 3>, 3> rotateFace(std::array<std::array<std::string, 3>, 3> face2Rot, int distanceChoice);



   // void moveWhiteToFirst();
};



#endif
