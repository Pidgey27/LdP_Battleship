//
// Created by Aless on 21/12/2022.
//
#include "Coordinates.h"
#include <iostream>

Coordinates::Coordinates(std::string xy) {
    if(xy.size()==2) {
        coord_X=xy[0]-65;
        coord_Y=xy[1]-49;
    }
    if(xy.size()==3){
        coord_X=xy[0]-65;
        coord_Y=xy[2]-39;
    }
}