#ifndef RUBIKSCUBE_HPP
#define RUBIKSCUBE_HPP
#include <iostream>
#include <array>
#include <string>
#include <map>
#include <vector>
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

    std::vector<std::array<std::array<RubiksPiece, 3>, 3>> allFaces {
    topFace,
    firstFace,
    secondFace,
    thirdFace,
    fourthFace,
    bottomFace
};


std::vector<std::pair<int, int>> crossPositions = {
    std::make_pair(0, 1), 
    std::make_pair(1, 2), 
    std::make_pair(2, 1),
    std::make_pair(1, 0)
};

std::vector<std::pair<int, int>> cornerPositions = {
    std::make_pair(0, 0), 
    std::make_pair(0, 2), 
    std::make_pair(2, 2),
    std::make_pair(2, 0)
};
    //add in a queue/list/whatever which shows the messup moves that were done,
    // and then another one that shows the moves done to solve the cube
    
    public:
    
    
    rCube();
    std::array<std::array<RubiksPiece, 3>, 3> setupEdgeType(std::array<std::array<RubiksPiece, 3>, 3> face);
    //import from File
    void messUp(int numMoves,int snapShot);
    void printCube();
    void printCubeCross();
    void movement(Move moveChoice);
    //distanceChoice is in mult of 3
    void yMovement(int layerChoice, int distanceChoice);//need to work around stuff to rotate
    void xMovement(int layerChoice, int distanceChoice);
    void zMovement(int layerChoice, int distanceChoice); //ADD FACE ROTATION
 std::array<std::array<RubiksPiece, 3>, 3> rotateFace(std::array<std::array<RubiksPiece, 3>, 3> face2Rot, int distanceChoice);



    void moveWhiteToFirst(bool turn);
    void moveWhiteCross(std::pair<int, int> finalPos,Color connEdge);
    void moveWhiteCrossfromYellow(std::pair<int, int> finalPos,Color connEdge);
    void checkWhiteCross();
    void swappingFirstandThird(std::pair<int, int> finalPos,Color connEdge);

    void firstLayerFinish();
    void cornerToYellow(std::pair<Color, Color> colorPair, Color topCenterColor);
    void cornerYellowtoWhite(std::pair<Color, Color> colorPair, Color topCenterColor);

    void secondLayerFinish();
    void secondLayerMovement(std::pair<Color, Color> colorPair, Color topCenterColor);
    void secLayerLeftMove();
    void secLayerRightMove();

    void lastLayerCross();
    void yellowCrossAlgo();

    void lastLayerCorners();
    void lastLayerAlgo7();
    void lastLayerAlgo8();
    void lastLayer0Yellow();
    void lastLayer1Yellow();
    void lastLayer2Yellow();

};



#endif
