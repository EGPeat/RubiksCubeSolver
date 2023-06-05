#include <iostream>
#include <array>
#include "rubikscube.cpp"
using std::cout;
using std::endl;

//re private the arrays

int main(void){

cout<<"Welcome to Evan's Rubik's Cube Scrambler and Solver Program"<<endl;

rCube RubiksCube;
//RubiksCube.printCube();
RubiksCube.debugprintCube();
//RubiksCube.yArray[2][6]=colorMap[Color::Green];
//RubiksCube.yArray[2][2]=colorMap[Color::Blue];
RubiksCube.xArray[0][5]=colorMap[Color::Orange];
RubiksCube.xArray[0][9]=colorMap[Color::Red];
RubiksCube.xMovement(0,3);
//RubiksCube.yMovement(0,3);
RubiksCube.debugprintCube();
//RubiksCube.xMovement(0,3);
//RubiksCube.debugprintCube();
//RubiksCube.messUp(20,4);


return 0;
}