#include <iostream>
#include <array>
#include "rubikscube.cpp"
using std::cout;
using std::endl;
//wip
//re private the arrays

int main(void){

cout<<"Welcome to Evan's Rubik's Cube Scrambler and Solver Program"<<endl;

rCube RubiksCube;
RubiksCube.printCube();

//RubiksCube.yArray[2][6]=colorMap[Color::Green];
//RubiksCube.yArray[2][2]=colorMap[Color::Blue];
//RubiksCube.xArray[0][5]=colorMap[Color::Orange];
//RubiksCube.xArray[0][9]=colorMap[Color::Red];
//RubiksCube.xMovement(0,3);
//RubiksCube.yMovement(0,3);
//RubiksCube.printCube();

RubiksCube.yMovement(0,3);
RubiksCube.printCube();
RubiksCube.xMovement(2,3);
RubiksCube.printCube();

//add in face rotation as well as adding in zmovement




/*
RubiksCube.xMovement(0,3);
RubiksCube.printCube();
RubiksCube.xMovement(2,3);
RubiksCube.printCube();
RubiksCube.xMovement(1,3);
RubiksCube.printCube();

RubiksCube.xMovement(0,-3);
RubiksCube.printCube();
RubiksCube.xMovement(2,-3);
RubiksCube.printCube();
RubiksCube.xMovement(1,-3);
RubiksCube.printCube();*/
//RubiksCube.messUp(20,4);


return 0;
}