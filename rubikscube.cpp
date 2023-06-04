#ifndef RUBIKSCUBE_CPP
#define RUBIKSCUBE_CPP
#include "rubikscube.hpp"
#include <iostream>
#include <array>
#include <cstring>

rCube:: rCube(){
for(int i=0;i<3;i++){
    for(int red=0;red<3;red++){
        yArray[i][red]=colorMap[Color::Red];
    }
    for(int green=3;green<6;green++){
        yArray[i][green]=colorMap[Color::Green];
    }
    for(int orange=6;orange<9;orange++){
        yArray[i][orange]=colorMap[Color::Orange];
    }
    for(int blue=9;blue<12;blue++){
        yArray[i][blue]=colorMap[Color::Blue];
    }
}

for(int i=0;i<3;i++){
    for(int red=0;red<3;red++){
        xArray[i][red]=colorMap[Color::Red];
    }
    for(int yellow=3;yellow<6;yellow++){
        xArray[i][yellow]=colorMap[Color::Yellow];
    }
    for(int orange=6;orange<9;orange++){
        xArray[i][orange]=colorMap[Color::Orange];
    }
    for(int brown=9;brown<12;brown++){
        xArray[i][brown]=colorMap[Color::Brown];
    }
}

for(int i=0;i<3;i++){
    for(int yellow=0;yellow<3;yellow++){
        zArray[i][yellow]=colorMap[Color::Yellow];
    }
    for(int green=3;green<6;green++){
        zArray[i][green]=colorMap[Color::Green];
    }
    for(int brown=6;brown<9;brown++){
        zArray[i][brown]=colorMap[Color::Brown];
    }
    for(int blue=9;blue<12;blue++){
        zArray[i][blue]=colorMap[Color::Blue];
    }
}



std::cout<<"\U0001F7E6"<<std::endl;

}





#endif