//
// Created by Aless on 21/12/2022.
//

#ifndef LDP_BATTLESHIP_COORDINATES_H
#define LDP_BATTLESHIP_COORDINATES_H
#include <iostream>
class Coordinates{
protected:
    int coord_X;
    int coord_Y;
public:
    Coordinates(int x, int y) : coord_X{x}, coord_Y{y} {};
    Coordinates(std::string xy);
    int get_X(){return coord_X;};
    int get_Y(){return coord_Y;};
};
#endif //LDP_BATTLESHIP_COORDINATES_H
