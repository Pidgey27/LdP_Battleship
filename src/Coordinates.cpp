//
// Created by Aless on 21/12/2022.
//
#include "Coordinates.h"
#include <iostream>
#include <algorithm>

Coordinates::Coordinates(std::string xy) {
    check_Invalid_Char(xy);
    xy= check_Lenght(xy);
    if(xy.size()==2) {
        coord_X=xy[0]-65;
        coord_Y=xy[1]-49;
    }
    if(xy.size()==3){
        coord_X=xy[0]-65;
        coord_Y=xy[2]-39;
    }
    if(coord_X>12)
        coord_X=coord_X-32;
    //if(coord_X>11||coord_Y>11||coord_X<0||coord_Y<0)
      //  throw std::runtime_error("Hai inserito delle coordinate invalide!");
}

void Coordinates::check_Invalid_Char(std::string xy) {
    std::string invalid="!£$%&/()=?^[]{}*ç@°#§+*-_;,<>òàùèé|";
    if(!xy.find(invalid)==std::string::npos)
        throw std::runtime_error("Hai inserito una stringa non valida!");
}
std::string Coordinates::check_Lenght(std::string xy) {
    xy.erase(remove(xy.begin(), xy.end(), ' '), xy.end());
    if(xy.size()>3)
        throw std::runtime_error("Hai inserito una stringa troppo lunga!");
    return xy;
}