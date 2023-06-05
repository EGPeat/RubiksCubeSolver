#ifndef RUBIKSCUBE_CPP
#define RUBIKSCUBE_CPP
#include "rubikscube.hpp"
#include <iostream>
#include <array>
#include <cstring>
#include <random>
#include <queue>

rCube:: rCube(){
for(int i=0;i<3;i++){
    for(int white=0;white<3;white++){
        yArray[i][white]=colorMap[Color::White];
    }
    for(int orange=3;orange<6;orange++){
        yArray[i][orange]=colorMap[Color::Orange];
    }
    for(int yellow=6;yellow<9;yellow++){
        yArray[i][yellow]=colorMap[Color::Yellow];
    }
    for(int red=9;red<12;red++){
        yArray[i][red]=colorMap[Color::Red];
    }
}

for(int i=0;i<3;i++){
    for(int white=0;white<3;white++){
        xArray[i][white]=colorMap[Color::White];
    }
    for(int blue=3;blue<6;blue++){
        xArray[i][blue]=colorMap[Color::Blue];
    }
    for(int yellow=6;yellow<9;yellow++){
        xArray[i][yellow]=colorMap[Color::Yellow];
    }
    for(int green=9;green<12;green++){
        xArray[i][green]=colorMap[Color::Green];
    }
}

for(int i=0;i<3;i++){
    for(int blue=0;blue<3;blue++){
        zArray[i][blue]=colorMap[Color::Blue];
    }
    for(int red=3;red<6;red++){
        zArray[i][red]=colorMap[Color::Red];
    }
    for(int green=6;green<9;green++){
        zArray[i][green]=colorMap[Color::Green];
    }
    for(int orange=9;orange<12;orange++){
        zArray[i][orange]=colorMap[Color::Orange];
    }
}




}

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

 void rCube::printCube(){
std::cout<<"Printed Cube:"<<std::endl;

for(int i=0;i<3;i++){ //top part
    for(int j=3;j<6;j++){
        std::cout<<xArray[i][j];
    }
    std::cout<<std::endl;
}


for(int i=0;i<3;i++){ //main line
    for(int j=0;j<12;j++){
        std::cout<<yArray[i][j];
    }
    std::cout<<std::endl;
}


for(int i=0;i<3;i++){ //bottom part
    for(int j=9;j<12;j++){
        std::cout<<xArray[i][j];
    }
    std::cout<<std::endl;
}

 }


void rCube::debugprintCube(){

std::cout<<"Printed Debug Cube:"<<std::endl;


for(int i=0;i<3;i++){ //main line
    for(int j=0;j<12;j++){
        std::cout<<yArray[i][j];
    }
    std::cout<<std::endl;
}
//std::cout<<std::endl;
for(int i=0;i<3;i++){ //main line
    for(int j=0;j<12;j++){
        std::cout<<xArray[i][j];
    }
    std::cout<<std::endl;
}
//std::cout<<std::endl;
for(int i=0;i<3;i++){ //main line
    for(int j=0;j<12;j++){
        std::cout<<zArray[i][j];
    }
    std::cout<<std::endl;
}


}
void rCube::yMovement(int layerChoice, int distanceChoice){

std::array<std::array<std::string, 12>, 3> tempyArray=yArray;
for(int i=24;i<36;i++){
    yArray[layerChoice][(i+distanceChoice)%12]=tempyArray[layerChoice][(i%12)];

}
for(int i=24;i<27;i++){
    xArray[(i)%12][2-layerChoice]=yArray[layerChoice][(i)%12];
    xArray[(i)%12][6+layerChoice]=yArray[layerChoice][(i+6)%12];
    zArray[(i)%12][3+layerChoice]=yArray[layerChoice][(i+9)%12]; //gotta check it works right for things in the rows
    zArray[(i)%12][11-layerChoice]=yArray[layerChoice][(5-(i%12))];
}
}

void rCube::xMovement(int layerChoice, int distanceChoice){

std::array<std::array<std::string, 12>, 3> tempxArray=xArray;
for(int i=24;i<36;i++){
    xArray[layerChoice][(i+distanceChoice)%12]=tempxArray[layerChoice][(i%12)];

}
for(int i=24;i<27;i++){

    //change xarray and y array and such
        yArray[(i)%12][layerChoice]=xArray[layerChoice][(i)%12];
        //yArray[(i)%12][6+layerChoice]=xArray[layerChoice][(i+6)%12];


 //   xArray[(i)%12][2-layerChoice]=yArray[layerChoice][(i)%12];
//    xArray[(i)%12][6+layerChoice]=yArray[layerChoice][(i+6)%12];
//    zArray[(i)%12][3+layerChoice]=yArray[layerChoice][(i+9)%12]; //gotta check it works right for things in the rows
//    zArray[(i)%12][11-layerChoice]=yArray[layerChoice][(5-(i%12))];
}
}



#endif