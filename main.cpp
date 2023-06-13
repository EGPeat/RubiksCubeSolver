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


 //         RubiksCube.messUp(30,30);

        //RubiksCube.movement(Move::Right);
        //RubiksCube.movement(Move::rotateZPr);

         /*RubiksCube.movement(Move::Top);
         RubiksCube.movement(Move::Back);
         RubiksCube.movement(Move::Back);
         RubiksCube.movement(Move::TopPr);
         RubiksCube.movement(Move::BackPr);
         RubiksCube.movement(Move::Top);
         RubiksCube.movement(Move::Back);
         RubiksCube.movement(Move::TopPr);


        RubiksCube.printCubeCross();*/
        








 



RubiksCube.messUp(30,30);
//RubiksCube.printCubeCross();
RubiksCube.checkWhiteCross();
           RubiksCube.moveWhiteToFirst(false);
            RubiksCube.checkWhiteCross();
            RubiksCube.firstLayerFinish();
            RubiksCube.printCubeCross();
            RubiksCube.secondLayerFinish();
             RubiksCube.printCubeCross();
//move white cross into correct position, then white edges
//then move second row centers to right spot 




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
