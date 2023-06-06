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
RubiksCube.printCubeCross();


//RubiksCube.messUp(20,20);
//RubiksCube.printCubeCross();

//RubiksCube.printCube();




return 0;
}

//good generalized testing setup, can modify to check other things
/*RubiksCube.xMovement(2,-3);
RubiksCube.printCube();
RubiksCube.zMovement(2,3);
RubiksCube.printCube();
RubiksCube.xMovement(0,3);
RubiksCube.printCube();
RubiksCube.yMovement(0,3);
RubiksCube.printCube();*/
