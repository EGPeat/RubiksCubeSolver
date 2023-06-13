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
    std::cout<<"Moving White to FirstFace"<<std::endl;
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

        printCubeCross();
        swappingFirstandThird(finalPos, connEdge); 
        printCubeCross();

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



#endif
