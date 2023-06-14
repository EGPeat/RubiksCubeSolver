#include <iostream>
#include <array>
#include "rubikscube.cpp"
using std::cout;
using std::endl;


int main(void){

cout<<"Welcome to Evan's Rubik's Cube Scrambler and Solver Program"<<endl;

rCube RubiksCube;

RubiksCube.printCubeCross();
RubiksCube.messUp(30,30);
RubiksCube.checkWhiteCross();
RubiksCube.moveWhiteToFirst(false);
RubiksCube.checkWhiteCross();
RubiksCube.firstLayerFinish();
RubiksCube.printCubeCross();
RubiksCube.secondLayerFinish();
RubiksCube.printCubeCross();
RubiksCube.lastLayerCross();
RubiksCube.printCubeCross();
RubiksCube.lastLayerCorners();
RubiksCube.printCubeCross();
RubiksCube.makingYellowCorners();
RubiksCube.printCubeCross();
RubiksCube.yellowFinalPermute();
RubiksCube.printCubeCross();
     






return 0;
}
