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
        std::cout<<"\U00002B1B ";
        for(int j=0;j<3;j++){
            std::cout<<secondFace[i][j]._emoji;
        }
        std::cout<<"\U00002B1B ";
        for(int j=0;j<3;j++){
            std::cout<<thirdFace[i][j]._emoji;
        }
        std::cout<<"\U00002B1B ";
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
        for(int j=0;j<4;j++){
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
        std::cout<<"\U00002B1B ";
        for(int j=0;j<3;j++){
            std::cout<<firstFace[i][j]._emoji;
        }
        std::cout<<"\U00002B1B ";
        for(int j=0;j<3;j++){
            std::cout<<secondFace[i][j]._emoji;
        }
        std::cout<<"\U00002B1B ";
        for(int j=0;j<3;j++){
            std::cout<<thirdFace[i][j]._emoji;
        }
        
        std::cout<<std::endl;
    }
std::cout<<std::endl;



    for(int i=0;i<3;i++){ //bottom part
        for(int j=0;j<4;j++){
            std::cout<<"\U00002B1B ";
        }
        for(int j=0;j<3;j++){
            std::cout<<bottomFace[i][j]._emoji;
        }
        std::cout<<std::endl;
    }



}












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
            //printCube();
            printCubeCross();
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



 




std::array<std::array<RubiksPiece, 3>, 3> rCube::rotateFace(std::array<std::array<RubiksPiece, 3>, 3> face2Rot, int distanceChoice){//my implementation wont work for rotations past 3
    std::array<std::array<RubiksPiece, 3>, 3> tempFace=face2Rot;

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
std::array<std::array<RubiksPiece, 3>, 3> tempyArray=firstFace;

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
std::array<std::array<RubiksPiece, 3>, 3> tempyArray=firstFace;

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
std::array<std::array<RubiksPiece, 3>, 3> tempyArray=topFace;

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



void rCube::moveWhiteToFirst(bool turn){
    if(turn==false){
    }
    if( firstFace[1][1]._color==Color::White){
        return;
    }

    else if(thirdFace[1][1]._color==Color::White){
        movement(Move::rotateX);
        movement(Move::rotateX);
    }
    else if (turn==false){
        movement(Move::rotateX);
        moveWhiteToFirst(true);
    }
    else{
        movement(Move::rotateY);
    }


}

void rCube::checkWhiteCross(){
std::array<Color,4> edgeColorWC={Color::Blue,Color::Red,Color::Green,Color::Orange};


for(int i=0;i<crossPositions.size();i++){
    int row = crossPositions[i].first;
    int col = crossPositions[i].second;
    
    if((firstFace[row][col]._color!=Color::White )||(firstFace[row][col]._connectedColors.at(0)!=edgeColorWC[i] )){
        moveWhiteCross(crossPositions[i],edgeColorWC[i]);
    }
    
}

}

void rCube::moveWhiteCrossfromYellow(std::pair<int, int> finalPos,Color connEdge){
  int backCol;
  if(finalPos.second==0){
    backCol=2;
  }
  else if(finalPos.second==2){
    backCol=0;
  }
  else{
    backCol=1;
  }

  for(int i=0;i<crossPositions.size();i++){//checks the back of the cube relative to white face and then moves to position
    int row = crossPositions[i].first;
    int col = crossPositions[i].second;
    
    if((thirdFace[row][col]._color==Color::White )&&(thirdFace[row][col]._connectedColors.at(0)==connEdge )){


        
while((thirdFace[finalPos.first][backCol]._color!=Color::White )||(thirdFace[finalPos.first][backCol]._connectedColors.at(0)!=connEdge )){
     movement(Move::Back);
        }
        swappingFirstandThird(finalPos, connEdge); 

    }
    
}  
}


void rCube::swappingFirstandThird(std::pair<int, int> finalPos,Color connEdge){
if(finalPos==crossPositions[0]){
    movement(Move::Top);
    movement(Move::Top);
}
else if(finalPos==crossPositions[1]){
    movement(Move::Right);
    movement(Move::Right);
}
else if(finalPos==crossPositions[2]){
    movement(Move::Bottom);
    movement(Move::Bottom);
}
else{
    movement(Move::Left);
    movement(Move::Left);
}



}

void rCube::moveWhiteCross(std::pair<int, int> finalPos,Color connEdge){


    int row = finalPos.first;
    int col = finalPos.second;
    

    for(int i=0;i<allFaces.size();i++){//checking each face for the piece
        for(int j=0;j<crossPositions.size();j++){//checking each valid position on the cube
            int rowCheck=crossPositions[j].first;
            int colCheck=crossPositions[j].second;

        if((i==1)&&(firstFace[rowCheck][colCheck]._color==Color::White )&&(firstFace[rowCheck][colCheck]._connectedColors[0]==connEdge)){
            swappingFirstandThird(std::make_pair(rowCheck, colCheck), connEdge); 
            moveWhiteCrossfromYellow(finalPos,connEdge);
            return;
        }

        else if((i==3)&&(thirdFace[rowCheck][colCheck]._color==Color::White )&&(thirdFace[rowCheck][colCheck]._connectedColors[0]==connEdge)){      
            moveWhiteCrossfromYellow(finalPos,connEdge);
            return;
        }


        else if((i==0)&&(topFace[rowCheck][colCheck]._color==Color::White )&&(topFace[rowCheck][colCheck]._connectedColors[0]==connEdge)){ 
             if((topFace[0][1]._color==Color::White)&&(topFace[0][1]._connectedColors[0]==connEdge)){
                    movement(Move::TopPr);
                    movement(Move::LeftPr);
                    movement(Move::Back);
                    movement(Move::Left);
                    movement(Move::Top);
             }
             else  if((topFace[1][2]._color==Color::White)&&(topFace[1][2]._connectedColors[0]==connEdge)){
                    
                    movement(Move::Right);
                    movement(Move::Back);
                    movement(Move::RightPr);
                    
             }
             else  if((topFace[2][1]._color==Color::White)&&(topFace[2][1]._connectedColors[0]==connEdge)){
                    movement(Move::Top);
                    movement(Move::LeftPr);
                    movement(Move::Back);
                    movement(Move::Left);
                    movement(Move::TopPr);
             }
             else  if((topFace[1][0]._color==Color::White)&&(topFace[1][0]._connectedColors[0]==connEdge)){
                    movement(Move::LeftPr);
                    movement(Move::Back);
                    movement(Move::Left);
             }
            moveWhiteCrossfromYellow(finalPos,connEdge);
            return;

        }


  else if((i==5)&&(bottomFace[rowCheck][colCheck]._color==Color::White )&&(bottomFace[rowCheck][colCheck]._connectedColors[0]==connEdge)){ 
             if((bottomFace[0][1]._color==Color::White)&&(bottomFace[0][1]._connectedColors[0]==connEdge)){
                    movement(Move::BottomPr);
                    movement(Move::Left);
                    movement(Move::BackPr);
                    movement(Move::LeftPr);
                    movement(Move::Bottom);
             }
             else  if((bottomFace[1][2]._color==Color::White)&&(bottomFace[1][2]._connectedColors[0]==connEdge)){
                    
                    movement(Move::RightPr);
                    movement(Move::BackPr);
                    movement(Move::Right);
                    
             }
             else  if((bottomFace[2][1]._color==Color::White)&&(bottomFace[2][1]._connectedColors[0]==connEdge)){
                    movement(Move::Bottom);
                    movement(Move::Left);
                    movement(Move::BackPr);
                    movement(Move::LeftPr);
                    movement(Move::BottomPr);
             }
             else  if((bottomFace[1][0]._color==Color::White)&&(bottomFace[1][0]._connectedColors[0]==connEdge)){
                    movement(Move::Left);
                    movement(Move::BackPr);
                    movement(Move::LeftPr);
             }
            moveWhiteCrossfromYellow(finalPos,connEdge);
            return;

        }


  else if((i==2)&&(secondFace[rowCheck][colCheck]._color==Color::White )&&(secondFace[rowCheck][colCheck]._connectedColors[0]==connEdge)){ 
             if((secondFace[0][1]._color==Color::White)&&(secondFace[0][1]._connectedColors[0]==connEdge)){
                   

                    movement(Move::TopPr);//good
                    movement(Move::Back);//good
                    movement(Move::Top);//good
             }
             //[1][2] is actually the type that needs a lot of moves
             else  if((secondFace[1][2]._color==Color::White)&&(secondFace[1][2]._connectedColors[0]==connEdge)){
                    movement(Move::RightPr);//good
                    movement(Move::TopPr);//good
                    movement(Move::Back);//good
                    movement(Move::Top);//good
                    movement(Move::Right);//good
                    
             }
             else  if((secondFace[2][1]._color==Color::White)&&(secondFace[2][1]._connectedColors[0]==connEdge)){
                   

                    movement(Move::Bottom);//good
                    movement(Move::BackPr);//good
                    movement(Move::BottomPr);//good
             }
             //[1][0] is actually the type that needs a lot of moves
             else  if((secondFace[1][0]._color==Color::White)&&(secondFace[1][0]._connectedColors[0]==connEdge)){
                    movement(Move::Right);//good
                    movement(Move::TopPr);//good
                    movement(Move::Back);//good
                    movement(Move::Top);//good
                    movement(Move::RightPr);//good
             }
           
            moveWhiteCrossfromYellow(finalPos,connEdge);
            return;

        }

 else if((i==4)&&(fourthFace[rowCheck][colCheck]._color==Color::White )&&(fourthFace[rowCheck][colCheck]._connectedColors[0]==connEdge)){ 
             if((fourthFace[0][1]._color==Color::White)&&(fourthFace[0][1]._connectedColors[0]==connEdge)){
                   
                    //normie one
                    movement(Move::Top);
                    movement(Move::BackPr);
                    movement(Move::TopPr);
             }
             //[1][2] is actually the type that needs a lot of moves
             else  if((fourthFace[1][2]._color==Color::White)&&(fourthFace[1][2]._connectedColors[0]==connEdge)){
                    movement(Move::LeftPr);//good
                    movement(Move::Top);//good
                    movement(Move::BackPr);//good
                    movement(Move::TopPr);//good
                    movement(Move::Left);//good
                    
             }
             else  if((fourthFace[2][1]._color==Color::White)&&(fourthFace[2][1]._connectedColors[0]==connEdge)){
                   

                    movement(Move::BottomPr);
                    movement(Move::Back);
                    movement(Move::Bottom);
             }
             //[1][0] is actually the type that needs a lot of moves
             else  if((fourthFace[1][0]._color==Color::White)&&(fourthFace[1][0]._connectedColors[0]==connEdge)){
                    movement(Move::Left);//good
                    movement(Move::Top);//good
                    movement(Move::BackPr);//good
                    movement(Move::TopPr);//good
                    movement(Move::LeftPr);//good
             }           
            moveWhiteCrossfromYellow(finalPos,connEdge);
            return;

        }

}
}
}






void rCube::cornerToYellow(std::pair<Color, Color> colorPair, Color topCenterColor){//this moves the corner to yellow.
// then another function will be called to move the corner to the white layer. This will be done in the larger function

    if((firstFace[0][0]._color==Color::White )&&(firstFace[0][0]._connectedColors.at(0)==colorPair.first )&&
    (firstFace[0][0]._connectedColors.at(1)==colorPair.second )){//correct placement already
       return;}
    

    for(int i=0;i<4;i++){//for rotating the white face to check all the spots
    if((firstFace[0][2]._color==Color::White )&&(firstFace[0][2]._connectedColors.at(0)==colorPair.first )&&
    (firstFace[0][2]._connectedColors.at(1)==colorPair.second )){//checking white to make sure the      
       movement(Move::Right);     
       movement(Move::BackPr); 
       movement(Move::RightPr);
       movement(Move::TopPr);
       movement(Move::Back);
       movement(Move::Top);       
       return;
    }
    
    movement(Move::rotateZPr);
}  

    for(int i=0;i<cornerPositions.size();i++){//yellow
    int row = crossPositions[i].first;
    int col = crossPositions[i].second;
    
    if((thirdFace[row][col]._color==Color::White )&&(thirdFace[row][col]._connectedColors.at(0)==colorPair.first )&&
    (thirdFace[row][col]._connectedColors.at(1)==colorPair.second )){//checking yellow to make sure the 
        
        return;
    }
    }


for(int i=0;i<4;i++){//for rotating the 
    for(int j=0;j<cornerPositions.size();j++){
    int row = crossPositions[j].first;
    int col = crossPositions[j].second;
    
    if((topFace[0][0]._color==Color::White )&&(topFace[0][0]._connectedColors.at(0)==colorPair.first )&&
    (topFace[0][0]._connectedColors.at(1)==colorPair.second )){
        movement(Move::LeftPr);
        movement(Move::Back);
        movement(Move::Left);
        movement(Move::TopPr);
        movement(Move::Left);
        movement(Move::Top);
        movement(Move::LeftPr);
        return;
    }
    if((topFace[0][2]._color==Color::White )&&(topFace[0][2]._connectedColors.at(0)==colorPair.first )&&
    (topFace[0][2]._connectedColors.at(1)==colorPair.second )){
        movement(Move::Right);
        movement(Move::BackPr);
        movement(Move::RightPr);
        movement(Move::Top);
        movement(Move::RightPr);
        movement(Move::TopPr);
        movement(Move::Right);
        return;
    }
    if((topFace[2][0]._color==Color::White )&&(topFace[2][0]._connectedColors.at(0)==colorPair.first )&&
    (topFace[2][0]._connectedColors.at(1)==colorPair.second )){
        movement(Move::LeftPr);
        movement(Move::BackPr);
        movement(Move::Left);
        return;
    }
    if((topFace[2][2]._color==Color::White )&&(topFace[2][2]._connectedColors.at(0)==colorPair.first )&&
    (topFace[2][2]._connectedColors.at(1)==colorPair.second )){
        movement(Move::Right);
        movement(Move::Back);
        movement(Move::RightPr);
        return;
    }
    
    }
    movement(Move::rotateZPr);
}



}

void rCube::cornerYellowtoWhite(std::pair<Color, Color> colorPair, Color topCenterColor){
    int killswitch=0;

while((thirdFace[0][2]._color!=Color::White )||
(thirdFace[0][2]._connectedColors.at(0)!=colorPair.first )||
    (thirdFace[0][2]._connectedColors.at(1)!=colorPair.second )
    ){// use && or ||
        killswitch++;
        movement(Move::Back);
        if(killswitch>10){
            return;
            //used to be break;
        }
    }
    movement(Move::Top);
    movement(Move::Back);
    movement(Move::Back);
    movement(Move::TopPr);
    movement(Move::BackPr);
    movement(Move::Top);
    movement(Move::Back);
    movement(Move::TopPr);
    return;
    
}

void rCube::firstLayerFinish(){
    std::array<Color,4> centerColor={Color::Blue,Color::Red,Color::Green,Color::Orange};
     std::array<std::pair<Color, Color>, 4> cornerColor={
    std::make_pair(Color::Blue,Color::Orange),
    std::make_pair(Color::Blue,Color::Red),
    std::make_pair(Color::Green,Color::Red),
    std::make_pair(Color::Green,Color::Orange)};



    for(int i=0;i<4;i++){  //for each white corner it runs
        Color backupColor=centerColor.at(i); // color on topface
        cornerToYellow(cornerColor.at(i),centerColor.at(i)); //finds and moves the corner to the right spot in the 3rdface
        while(topFace[1][1]._color!=backupColor){
            movement(Move::rotateZPr);
        }
   //     if (topFace[0][0]._connectedColors.at(0) != cornerColor.at(i).first ||
   //         topFace[0][0]._connectedColors.at(1) != cornerColor.at(i).second) {
        cornerYellowtoWhite(cornerColor.at(i),centerColor.at(i));
        //}
        while(topFace[1][1]._color!=backupColor){
            movement(Move::rotateZPr);
        }
    movement(Move::rotateZPr);
    }
}

void rCube::secLayerLeftMove(){
    movement(Move::BackPr);
    movement(Move::LeftPr);
    movement(Move::BackPr);
    movement(Move::Left);
    movement(Move::Back);
    movement(Move::Top);
    movement(Move::Back);
    movement(Move::TopPr);
}
void rCube::secLayerRightMove(){
    movement(Move::Back);
    movement(Move::Right);
    movement(Move::Back);
    movement(Move::RightPr);
    movement(Move::BackPr);
    movement(Move::TopPr);
    movement(Move::BackPr);
    movement(Move::Top);
}
void rCube::secondLayerMovement(std::pair<Color, Color> colorPair, Color topCenterColor){
for(int i=0;i<4;i++){
    if(topFace[0][1]._color==topFace[1][1]._color){
        if(topFace[0][1]._connectedColors.at(0)==fourthFace[1][1]._color){
            secLayerLeftMove();
            return;
        }
        else if(topFace[0][1]._connectedColors.at(0)==secondFace[1][1]._color){
            secLayerRightMove();
            return;
        }

    }



    movement(Move::rotateZPr);
    movement(Move::BackPr);//or back lol? 


}

while(topFace[1][1]._color!=topCenterColor){//move back to start
    movement(Move::rotateZPr); 
}
}



void rCube::secondLayerFinish(){ //really unoptimal, runs through stuff wayyyy too many times
Color backupColor;
for(int i=0;i<8;i++){
    backupColor=topFace[1][1]._color;
    if(topFace[0][1]._color!=Color::Yellow&&topFace[0][1]._connectedColors.at(0)!=Color::Yellow){//checking [0][1] is bad
    secondLayerMovement(std::make_pair(topFace[0][1]._color,topFace[0][1]._connectedColors.at(0)),backupColor);
    }
    
    movement(Move::rotateZPr); 
}



for(int i=0;i<8;i++){//moves pieces into the second layer then fixes them
    backupColor=topFace[1][1]._color;
    
    
    if((topFace[1][0]._color!=Color::Yellow && topFace[1][0]._connectedColors.at(0)!=Color::Yellow)&&
    !(topFace[1][0]._color==topFace[1][1]._color&&topFace[1][0]._connectedColors.at(0)==fourthFace[1][1]._color)){
        secLayerLeftMove();
        movement(Move::Back);
        movement(Move::Back);
        secondLayerMovement(std::make_pair(topFace[0][1]._color,topFace[0][1]._connectedColors.at(0)),backupColor);
    }
    else if((topFace[1][2]._color!=Color::Yellow && topFace[1][2]._connectedColors.at(0)!=Color::Yellow)&&
    !(topFace[1][2]._color==topFace[1][1]._color&&topFace[1][2]._connectedColors.at(0)==secondFace[1][1]._color)){
        secLayerRightMove();
        movement(Move::Back);
        movement(Move::Back);
        secondLayerMovement(std::make_pair(topFace[0][1]._color,topFace[0][1]._connectedColors.at(0)),backupColor);
    }
    
    
    movement(Move::rotateZPr); 
}
for(int i=0;i<8;i++){//checks the topface for a
    backupColor=topFace[1][1]._color;
    if(topFace[0][1]._color!=Color::Yellow&&topFace[0][1]._connectedColors.at(0)!=Color::Yellow){//checking [0][1] is bad
    secondLayerMovement(std::make_pair(topFace[0][1]._color,topFace[0][1]._connectedColors.at(0)),backupColor);
    }
    
    movement(Move::rotateZPr); 
}

}
void rCube::yellowCrossAlgo(){
    movement(Move::Bottom);
    movement(Move::Right);
    movement(Move::Front);
    movement(Move::RightPr);
    movement(Move::FrontPr);
    movement(Move::BottomPr);

}
void rCube::lastLayerCross(){
    movement(Move::rotateYPr);
    movement(Move::rotateYPr);

while(
    (firstFace[0][1]._color!=Color::Yellow)||(firstFace[1][0]._color!=Color::Yellow)||(firstFace[1][2]._color!=Color::Yellow)||
    (firstFace[2][1]._color!=Color::Yellow)){
    if(
    (firstFace[0][1]._color!=Color::Yellow)&&(firstFace[1][0]._color!=Color::Yellow)&&(firstFace[1][2]._color!=Color::Yellow)&&
    (firstFace[2][1]._color!=Color::Yellow)){//only center is yellow
        yellowCrossAlgo();
    }
    if(firstFace[1][0]._color==Color::Yellow){
        if(firstFace[0][1]._color==Color::Yellow){
            yellowCrossAlgo();
            yellowCrossAlgo();
        }

        else if(firstFace[1][2]._color==Color::Yellow){
            yellowCrossAlgo();
        }

    }

    movement(Move::Front);
    }

}
void rCube::lastLayerAlgo7(){
    movement(Move::Right);
    movement(Move::Front);
    movement(Move::Front);
    movement(Move::RightPr);

    movement(Move::FrontPr);
    movement(Move::Right);

    movement(Move::FrontPr);
    movement(Move::RightPr);

}
void rCube::lastLayerAlgo8(){
    movement(Move::Right);
    movement(Move::Front);

    movement(Move::RightPr);
    movement(Move::Front);

    movement(Move::Right);
    movement(Move::Front);
    movement(Move::Front);
    movement(Move::RightPr);
}

void rCube::lastLayer0Yellow(){


for(int i=0;i<5;i++){

    if(bottomFace[0][2]._color==Color::Yellow&&bottomFace[0][0]._color==Color::Yellow&&topFace[2][0]._color==Color::Yellow&&topFace[2][2]._color==Color::Yellow){
        lastLayerAlgo7();
        lastLayerAlgo7();
    }

    else if(bottomFace[0][2]._color==Color::Yellow&&fourthFace[0][2]._color==Color::Yellow&&fourthFace[2][2]._color==Color::Yellow&&topFace[2][2]._color==Color::Yellow){
        lastLayerAlgo7();
        movement(Move::FrontPr);
        lastLayerAlgo7();

    }


movement(Move::Front);
}

}





void rCube::lastLayer1Yellow(){

for(int i=0;i<5;i++){
    if(bottomFace[0][2]._color==Color::Yellow&&firstFace[2][0]._color==Color::Yellow){
        lastLayerAlgo8();
        return;
    }
    else if(secondFace[2][0]._color==Color::Yellow&&firstFace[0][2]._color==Color::Yellow){
        lastLayerAlgo7();
        return;
    }


    movement(Move::Front);
}


}
void rCube::lastLayer2Yellow(){
for(int i=0;i<5;i++){

    if(fourthFace[0][2]._color==Color::Yellow&&secondFace[0][0]._color==Color::Yellow){//headlights but to side. Algo7+U+Algo8
    lastLayerAlgo7();
    movement(Move::Front);
    lastLayerAlgo8();
    }

    else if(secondFace[0][0]._color==Color::Yellow&&secondFace[2][0]._color==Color::Yellow){
        lastLayerAlgo7();
        movement(Move::FrontPr);
        lastLayerAlgo8();
    }

    else if(bottomFace[0][0]._color==Color::Yellow&&firstFace[0][0]._color==Color::Yellow){
        lastLayerAlgo7();
        movement(Move::Front);
        movement(Move::Front);
        lastLayerAlgo8();
    }





movement(Move::Front);
}

}



void rCube::lastLayerCorners(){

int numCornerYellow=0;

 for(int i=0;i<cornerPositions.size();i++){//yellow
    int row = cornerPositions[i].first;
    int col = cornerPositions[i].second;
    if(firstFace[row][col]._color==Color::Yellow){
        
        numCornerYellow+=1;

    }
    }
    

    if(numCornerYellow==0){
        lastLayer0Yellow();
        return;
    }
    else if(numCornerYellow==1){
        lastLayer1Yellow();
        return;
    }
    else if(numCornerYellow==2){
        lastLayer2Yellow();
        return;
    }
    else if(numCornerYellow==4){
        return;
    }


}

void rCube::yellowCornerAlgo(){

    movement(Move::Right);
    movement(Move::TopPr);
    movement(Move::Right);
    movement(Move::Bottom);
    movement(Move::Bottom);
    movement(Move::RightPr);
    movement(Move::Top);
    movement(Move::Right);
    movement(Move::Bottom);
    movement(Move::Bottom);
    movement(Move::Right);
    movement(Move::Right);

    





}
void rCube::makingYellowCorners(){

    if( topFace[2][2]._color==topFace[2][0]._color&&
        fourthFace[2][2]._color==fourthFace[0][2]._color&&
        bottomFace[0][0]._color==bottomFace[0][2]._color&&
        secondFace[0][0]._color==secondFace[2][0]._color){
        return;
    }
    else if(topFace[2][2]._color==topFace[2][0]._color){
        movement(Move::Front);
        movement(Move::Front);
        yellowCornerAlgo();
        return;
    }
    else if(fourthFace[2][2]._color==fourthFace[0][2]._color){
        movement(Move::FrontPr);
        yellowCornerAlgo();
        return;
    }
    else if(bottomFace[0][0]._color==bottomFace[0][2]._color){
        yellowCornerAlgo();
        return;
    }
    else if(secondFace[0][0]._color==secondFace[2][0]._color){
        movement(Move::Front);
        yellowCornerAlgo();
        return;
    }
    else{
        yellowCornerAlgo();
        movement(Move::FrontPr);
        yellowCornerAlgo();
        return;
    }



}


void rCube::yellowFinalPermuteHelper(){
    while(
        bottomFace[0][0]._color==bottomFace[0][1]._color||
        fourthFace[2][2]._color==fourthFace[1][2]._color||
         secondFace[0][0]._color==secondFace[1][0]._color

    ){

    movement(Move::Front);
 
    }
    


    while(bottomFace[0][0]._color!=bottomFace[0][1]._color){
        
    movement(Move::Right);
    movement(Move::FrontPr);
    movement(Move::Right);
    movement(Move::Front); 
    movement(Move::Right);
    movement(Move::Front);
    movement(Move::Right);
    movement(Move::FrontPr);
    movement(Move::RightPr);
    movement(Move::FrontPr);
    movement(Move::Right);
    movement(Move::Right);


    }


}
void rCube::yellowFinalPermute(){

     if( topFace[2][2]._color==topFace[2][1]._color&&
        fourthFace[2][2]._color==fourthFace[1][2]._color&&
        bottomFace[0][0]._color==bottomFace[0][1]._color&&
        secondFace[0][0]._color==secondFace[2][0]._color){
            while(bottomFace[0][1]._color!=bottomFace[1][1]._color){
        movement(Move::Front);
    }
        return;
    }

    yellowFinalPermuteHelper();

    
    if( secondFace[0][0]._color!=secondFace[1][0]._color){
        movement(Move::Front);
        movement(Move::Front);
        yellowFinalPermuteHelper();
    }

    while(bottomFace[0][1]._color!=bottomFace[1][1]._color){
        movement(Move::Front);
    }
}




#endif
