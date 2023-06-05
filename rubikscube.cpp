#ifndef RUBIKSCUBE_CPP
#define RUBIKSCUBE_CPP
#include "rubikscube.hpp"
#include <iostream>
#include <array>
#include <cstring>
#include <random>
#include <queue>
//wip

rCube:: rCube(){


for(int i=0;i<3;i++){
    for(int blue=0;blue<3;blue++){
        topFace[i][blue]=colorMap[Color::Blue];
    }
    for(int green=0;green<3;green++){
        bottomFace[i][green]=colorMap[Color::Green];
    }
    for(int white=0;white<3;white++){
        firstFace[i][white]=colorMap[Color::White];
    }
    for(int red=0;red<3;red++){
        secondFace[i][red]=colorMap[Color::Red];
    }
    for(int yellow=0;yellow<3;yellow++){
        thirdFace[i][yellow]=colorMap[Color::Yellow];
    }
    for(int orange=0;orange<3;orange++){
        fourthFace[i][orange]=colorMap[Color::Orange];
    }
    
}


}
/*
void rCube::messUp(int numMoves,int snapShot){
     std::random_device rd; 
    std::mt19937 mt(rd()); 
    std::queue<Move> moveQue;
    int snap=0;
    
    for (int i = 0; i < numMoves; ++i) {
        int choice=mt()% 18;
        moveQue.push(static_cast<Move>(choice));
        }
    while(moveQue.empty()!=true){
        movement(moveQue.front());
        moveQue.pop();
        snap+=1;
        if(snap%snapShot==0){
            printCube();
        }      
    }    



}
*/
/*
void rCube::movement(Move movechoice){
switch (movechoice) {
        case Move::Right:
            std::cout << "Performing Right move" << std::endl;
            yMovement( 0,  3); //not actually ymovements, should be x i think...
            break;
        case Move::RightPr:
            std::cout << "Performing RightPr move" << std::endl;
            yMovement( 0,  -3); //not actually ymovements, should be x i think...
            break;
        case Move::Left:
            std::cout << "Performing Left move" << std::endl;
            //yMovement(2,-3)  //3 or -3? idk
            break;
        case Move::LeftPr:
            std::cout << "Performing LeftPr move" << std::endl;
            break;
        case Move::Up:
            std::cout << "Performing Up move" << std::endl;
            break;
        case Move::UpPr:
            std::cout << "Performing UpPr move" << std::endl;
            break;
        case Move::Down:
            std::cout << "Performing Down move" << std::endl;
            break;
        case Move::DownPr:
            std::cout << "Performing DownPr move" << std::endl;
            break;
        case Move::Front:
            std::cout << "Performing Front move" << std::endl;
            break;
        case Move::FrontP:
            std::cout << "Performing FrontP move" << std::endl;
            break;
        case Move::Back:
            std::cout << "Performing Back move" << std::endl;
            break;
        case Move::BackPr:
            std::cout << "Performing BackPr move" << std::endl;
            break;
        case Move::rotateZ:
            std::cout << "Performing RotateZ move" << std::endl;
            break;
        case Move::rotateZPr:
            std::cout << "Performing RotateZPr move" << std::endl;
            break;
              case Move::rotateY:
            std::cout << "Performing RotateY move" << std::endl;
            break;
        case Move::rotateYPr:
            std::cout << "Performing RotateYPr move" << std::endl;
            break;
        case Move::rotateX:
            std::cout << "Performing RotateX move" << std::endl;
            break;
        case Move::rotateXPr:
            std::cout << "Performing RotateXPr move" << std::endl;
            break;
    }

}
*/
 void rCube::printCube(){
std::cout<<"Printed Cube:"<<std::endl;

    for(int i=0;i<3;i++){ //top part
        for(int j=0;j<3;j++){
            std::cout<<topFace[i][j];
        }
        std::cout<<std::endl;
    }
std::cout<<std::endl;
    for(int i=0;i<3;i++){ //main line
        for(int j=0;j<3;j++){
            std::cout<<firstFace[i][j];
        }
        for(int j=0;j<3;j++){
            std::cout<<secondFace[i][j];
        }
        for(int j=0;j<3;j++){
            std::cout<<thirdFace[i][j];
        }
        for(int j=0;j<3;j++){
            std::cout<<fourthFace[i][j];
        }
        std::cout<<std::endl;
    }
std::cout<<std::endl;
    for(int i=0;i<3;i++){ //bottom part
        for(int j=0;j<3;j++){
            std::cout<<bottomFace[i][j];
        }
        std::cout<<std::endl;
    }

}



void rCube::xMovement(int layerChoice, int distanceChoice){
std::array<std::array<std::string, 3>, 3> tempyArray=firstFace;

for(int i=0;i<3;i++){
    if(distanceChoice<0){firstFace[i][layerChoice]=topFace[i][layerChoice];}
    else{firstFace[i][layerChoice]=bottomFace[i][layerChoice];}
}

for(int i=0;i<3;i++){
    if(distanceChoice<0){topFace[i][layerChoice]=thirdFace[2-i][2-layerChoice];}
    else{bottomFace[i][layerChoice]=thirdFace[2-i][2-layerChoice];}
}

for(int i=0;i<3;i++){
    if(distanceChoice<0){thirdFace[2-i][2-layerChoice]=bottomFace[i][layerChoice];}
    else{thirdFace[2-i][2-layerChoice]=topFace[i][layerChoice];}
}


for(int i=0;i<3;i++){
    if(distanceChoice<0){bottomFace[i][layerChoice]=tempyArray[i][layerChoice];}
    else{topFace[i][layerChoice]=tempyArray[i][layerChoice];}
}


if(layerChoice!=1){
    if(layerChoice==0){
        
        fourthFace=rotateFace(fourthFace,-1*distanceChoice);
    }
    else{
        secondFace=rotateFace(secondFace,distanceChoice); //do these two do weird things? test more
    }
}

}






std::array<std::array<std::string, 3>, 3> rCube::rotateFace(std::array<std::array<std::string, 3>, 3> face2Rot, int distanceChoice){//my implementation wont work for rotations past 3
std::array<std::array<std::string, 3>, 3> tempFace=face2Rot;

if(distanceChoice>0){
    face2Rot[0][1]=tempFace[1][0];
    face2Rot[1][2]=tempFace[0][1];
    face2Rot[2][1]=tempFace[1][2];
    face2Rot[1][0]=tempFace[2][1];

    face2Rot[0][0]=tempFace[2][0];
    face2Rot[0][2]=tempFace[0][0];
    face2Rot[2][2]=tempFace[0][2];
    face2Rot[2][0]=tempFace[2][2];


}

else{
face2Rot[1][0]=tempFace[0][1];
face2Rot[0][1]=tempFace[1][2];
face2Rot[1][2]=tempFace[2][1];
face2Rot[2][1]=tempFace[1][0];

face2Rot[2][0]=tempFace[0][0];
face2Rot[0][0]=tempFace[0][2];
face2Rot[0][2]=tempFace[2][2];
face2Rot[2][2]=tempFace[2][0];


}

return face2Rot;
}



void rCube::yMovement(int layerChoice, int distanceChoice){
std::array<std::array<std::string, 3>, 3> tempyArray=firstFace;

for(int i=0;i<3;i++){
    if(distanceChoice>0){firstFace[layerChoice][i]=secondFace[layerChoice][i];}
    else{firstFace[layerChoice][i]=fourthFace[layerChoice][i];}
}





for(int i=0;i<3;i++){
    if(distanceChoice>0){secondFace[layerChoice][i]=thirdFace[layerChoice][i];}
    else{fourthFace[layerChoice][i]=thirdFace[layerChoice][i];}
}

for(int i=0;i<3;i++){
    if(distanceChoice>0){thirdFace[layerChoice][i]=fourthFace[layerChoice][i];}
    else{thirdFace[layerChoice][i]=secondFace[layerChoice][i];}
}


for(int i=0;i<3;i++){
    if(distanceChoice>0){fourthFace[layerChoice][i]=tempyArray[layerChoice][i];}
    else{secondFace[layerChoice][i]=tempyArray[layerChoice][i];}
}


if(layerChoice!=1){
    if(layerChoice==0){
        
        topFace=rotateFace(topFace,distanceChoice);
    }
    else{
        bottomFace=rotateFace(bottomFace,-1*distanceChoice); //do these two do weird things? test more
    }
}

}






void rCube::zMovement(int layerChoice, int distanceChoice){
std::array<std::array<std::string, 3>, 3> tempyArray=topFace;

for(int i=0;i<3;i++){
    if(distanceChoice>0){topFace[2-layerChoice][i]=fourthFace[2-i][2-layerChoice];}
    else{topFace[2-layerChoice][i]=secondFace[i][layerChoice];}
}





for(int i=0;i<3;i++){
    if(distanceChoice>0){fourthFace[i][2-layerChoice]=bottomFace[layerChoice][i];}

   // [0][0]=[0][0]
  //  [1][0]=[0][1]
 //   [2][0]=[0][2]
    else{secondFace[2-i][layerChoice]=bottomFace[layerChoice][i];}
}

for(int i=0;i<3;i++){
    if(distanceChoice>0){bottomFace[layerChoice][i]=secondFace[2-i][layerChoice];}
  //  [0][0]=[2][0]
  //  [0][1]=[2][1]
   // [0][2]=[2][2]
    else{bottomFace[layerChoice][i]=fourthFace[i][2-layerChoice];}
}


for(int i=0;i<3;i++){ 
    if(distanceChoice>0){secondFace[i][layerChoice]=tempyArray[2-layerChoice][i];}
    //  [0][2]=[2][2]
  //  [1][2]=[2][1]
   // [2][2]=[2][0]
   else{fourthFace[i][2-layerChoice]=tempyArray[2-layerChoice][2-i];}
}


if(layerChoice!=1){
    if(layerChoice==0){
        
        firstFace=rotateFace(firstFace,distanceChoice);
    }
    else{
        thirdFace=rotateFace(thirdFace,-1*distanceChoice); //do these two do weird things? test more
    }
}

}





#endif