#ifndef RUBIKSCUBE_CPP
#define RUBIKSCUBE_CPP
#include "rubikscube.hpp"
#include "rubikspiece.hpp"
#include <iostream>
#include <array>
#include <cstring>
#include <random>
#include <queue>
//wip


std::array<std::array<RubiksPiece, 3>, 3> rCube::setupEdgeType(std::array<std::array<RubiksPiece, 3>, 3> face){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((i+j==1) ||(i+j==3)){
                face[i][j]._edgeType=Edge;
                
            }
            else if (i==1 && j==1){face[i][j]._edgeType=Center;}
            else{
                face[i][j]._edgeType=Corner;
            }
            

        }
    }

return face;
}
rCube:: rCube(){
    topFace=setupEdgeType(topFace);
    bottomFace=setupEdgeType(bottomFace);
    firstFace=setupEdgeType(firstFace);
    secondFace=setupEdgeType(secondFace);
    thirdFace=setupEdgeType(thirdFace);
    fourthFace=setupEdgeType(fourthFace);


for(int i=0;i<3;i++){
    for(int blue=0;blue<3;blue++){

        if(i==0){
            topFace[i][blue]._connectedColors.push_back(Color::Yellow);           
        }
        else if(i==2){
            topFace[i][blue]._connectedColors.push_back(Color::White);            
        }
        if(blue==0){
            topFace[i][blue]._connectedColors.push_back(Color::Orange);            
        }
        if(blue==2){
            topFace[i][blue]._connectedColors.push_back(Color::Red);            
        }
        topFace[i][blue]._color=Color::Blue;
        topFace[i][blue]._emoji=colorMap[Color::Blue];
    }

    for(int green=0;green<3;green++){

        if(i==0){
            bottomFace[i][green]._connectedColors.push_back(Color::White);
        }
        else if(i==2){
            bottomFace[i][green]._connectedColors.push_back(Color::Yellow);
        }
        if(green==0){
            bottomFace[i][green]._connectedColors.push_back(Color::Orange);   
        }
        if(green==2){
            bottomFace[i][green]._connectedColors.push_back(Color::Red);   
        }
        bottomFace[i][green]._color=Color::Green;
        bottomFace[i][green]._emoji=colorMap[Color::Green];
    }
    for(int white=0;white<3;white++){

        if(i==0){
            firstFace[i][white]._connectedColors.push_back(Color::Blue);
        }
        else if(i==2){
            firstFace[i][white]._connectedColors.push_back(Color::Green);
        }
        if(white==0){
            firstFace[i][white]._connectedColors.push_back(Color::Orange);  
        }
        if(white==2){
            firstFace[i][white]._connectedColors.push_back(Color::Red);   
        }
        firstFace[i][white]._color=Color::White;
        firstFace[i][white]._emoji=colorMap[Color::White];
    }
    for(int red=0;red<3;red++){

        if(i==0){
            secondFace[i][red]._connectedColors.push_back(Color::Blue);
        }
        else if(i==2){
            secondFace[i][red]._connectedColors.push_back(Color::Green);
        }
        if(red==0){
            secondFace[i][red]._connectedColors.push_back(Color::White);  
        }
        if(red==2){
            secondFace[i][red]._connectedColors.push_back(Color::Yellow);  
        }
        secondFace[i][red]._color=Color::Red;
        secondFace[i][red]._emoji=colorMap[Color::Red];
    }

    for(int yellow=0;yellow<3;yellow++){

        if(i==0){
            thirdFace[i][yellow]._connectedColors.push_back(Color::Blue);
        }
        else if(i==2){
            thirdFace[i][yellow]._connectedColors.push_back(Color::Green);
        }
        if(yellow==0){
            thirdFace[i][yellow]._connectedColors.push_back(Color::Red);   
        }
        if(yellow==2){
            thirdFace[i][yellow]._connectedColors.push_back(Color::Orange);   
        }
        thirdFace[i][yellow]._color=Color::Yellow;
        thirdFace[i][yellow]._emoji=colorMap[Color::Yellow];
    }
    for(int orange=0;orange<3;orange++){

        if(i==0){
            fourthFace[i][orange]._connectedColors.push_back(Color::Blue);
        }
        else if(i==2){
            fourthFace[i][orange]._connectedColors.push_back(Color::Green);
        }
        if(orange==0){
            fourthFace[i][orange]._connectedColors.push_back(Color::Yellow); 
        }
        if(orange==2){
            fourthFace[i][orange]._connectedColors.push_back(Color::White);   
        }
        fourthFace[i][orange]._color=Color::Orange;
        fourthFace[i][orange]._emoji=colorMap[Color::Orange];
    }

}

}


void rCube::printCube(){
std::cout<<"Printed Cube:"<<std::endl;

    for(int i=0;i<3;i++){ //top part
        for(int j=0;j<3;j++){
            std::cout<<topFace[i][j]._emoji;
        }
        std::cout<<std::endl;
    }
std::cout<<std::endl;
    for(int i=0;i<3;i++){ //main line
        for(int j=0;j<3;j++){
            std::cout<<firstFace[i][j]._emoji;
        }
        for(int j=0;j<3;j++){
            std::cout<<secondFace[i][j]._emoji;
        }
        for(int j=0;j<3;j++){
            std::cout<<thirdFace[i][j]._emoji;
        }
        for(int j=0;j<3;j++){
            std::cout<<fourthFace[i][j]._emoji;
        }
        std::cout<<std::endl;
    }
std::cout<<std::endl;
    for(int i=0;i<3;i++){ //bottom part
        for(int j=0;j<3;j++){
            std::cout<<bottomFace[i][j]._emoji;
        }
        std::cout<<std::endl;
    }

}

void rCube::printCubeCross(){
std::cout<<"Printed Cube:"<<std::endl;

    for(int i=0;i<3;i++){ //top part
        for(int j=0;j<3;j++){
            std::cout<<"\U00002B1B ";
        }
        for(int j=0;j<3;j++){
            std::cout<<topFace[i][j]._emoji;
        }
        std::cout<<std::endl;
    }
std::cout<<std::endl;
    for(int i=0;i<3;i++){ //main line
        for(int j=0;j<3;j++){
            std::cout<<fourthFace[i][j]._emoji;
        }
        for(int j=0;j<3;j++){
            std::cout<<firstFace[i][j]._emoji;
        }
        for(int j=0;j<3;j++){
            std::cout<<secondFace[i][j]._emoji;
        }
        for(int j=0;j<3;j++){
            std::cout<<thirdFace[i][j]._emoji;
        }
        
        std::cout<<std::endl;
    }
std::cout<<std::endl;
    for(int i=0;i<3;i++){ //bottom part
        for(int j=0;j<3;j++){
            std::cout<<"\U00002B1B ";
        }
        for(int j=0;j<3;j++){
            std::cout<<bottomFace[i][j]._emoji;
        }
        std::cout<<std::endl;
    }



}











/*
void rCube::messUp(int numMoves,int snapShot){
     std::random_device rd; 
    std::mt19937 mt(rd()); 
    std::queue<Move> moveQue;
    int snap=0;
    
    for (int i = 0; i < numMoves; ++i) {
        int choice=mt()% 12;
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
            xMovement(2,3);
            break;
        case Move::RightPr:
            std::cout << "Performing RightPr move" << std::endl;
            xMovement(2,-3);
            break;
        case Move::Left:
            std::cout << "Performing Left move" << std::endl;
            xMovement(0,-3);
            break;
        case Move::LeftPr:
            std::cout << "Performing LeftPr move" << std::endl;
            xMovement(0,3);
            break;
        case Move::Top:
            std::cout << "Performing Top move" << std::endl;
            yMovement(0,3); 
            break;
        case Move::TopPr:
            std::cout << "Performing TopPr move" << std::endl;
            yMovement(0,-3);
            break;
        case Move::Bottom:
            std::cout << "Performing Bottom move" << std::endl;
            yMovement(2,-3);
            break;
        case Move::BottomPr:
            std::cout << "Performing BottomPr move" << std::endl;
            yMovement(2,3);
            break;
        case Move::Front:
            std::cout << "Performing Front move" << std::endl;
            zMovement(0,3);
            break;
        case Move::FrontPr:
            std::cout << "Performing FrontP move" << std::endl;
            zMovement(0,-3);
            break;
        case Move::Back:
            std::cout << "Performing Back move" << std::endl;
            zMovement(2,-3);
            break;
        case Move::BackPr:
            std::cout << "Performing BackPr move" << std::endl;
            zMovement(2,3);
            break;
        case Move::rotateZ:
            std::cout << "Performing RotateZ move" << std::endl;
            zMovement(0,3);
            zMovement(1,3);
            zMovement(2,3);
            break;
        case Move::rotateZPr:
            std::cout << "Performing RotateZPr move" << std::endl;
            zMovement(0,-3);
            zMovement(1,-3);
            zMovement(2,-3);
            break;
        case Move::rotateY:
            std::cout << "Performing RotateY move" << std::endl;
            yMovement(0,3);
            yMovement(1,3);
            yMovement(2,3);
            break;
        case Move::rotateYPr:
            std::cout << "Performing RotateYPr move" << std::endl;
            yMovement(0,-3);
            yMovement(1,-3);
            yMovement(2,-3);
            break;
        case Move::rotateX:
            std::cout << "Performing RotateX move" << std::endl;
            xMovement(0,3);
            xMovement(1,3);
            xMovement(2,3);
            break;
        case Move::rotateXPr:
            std::cout << "Performing RotateXPr move" << std::endl;
            xMovement(0,-3);
            xMovement(1,-3);
            xMovement(2,-3);
            break;
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
            secondFace=rotateFace(secondFace,distanceChoice); 
        }
    }

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
            bottomFace=rotateFace(bottomFace,-1*distanceChoice); 
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
        else{bottomFace[layerChoice][i]=fourthFace[i][2-layerChoice];}
    }


    for(int i=0;i<3;i++){ 
        if(distanceChoice>0){secondFace[i][layerChoice]=tempyArray[2-layerChoice][i];}

    else{fourthFace[i][2-layerChoice]=tempyArray[2-layerChoice][2-i];}
    }

    if(layerChoice!=1){
        if(layerChoice==0){
            
            firstFace=rotateFace(firstFace,distanceChoice);
        }
        else{
            thirdFace=rotateFace(thirdFace,-1*distanceChoice); 
        }
    }

}



void rCube::moveWhiteToFirst(){

    //if( first.center!=white)
    //


}
*/


#endif
