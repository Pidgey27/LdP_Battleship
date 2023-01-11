//
// Created by Aless on 21/12/2022.
//

#ifndef LDP_BATTLESHIP_SHIP_H
#define LDP_BATTLESHIP_SHIP_H
#include "Coordinates.h"

class Ship {

protected:
    bool orientation;
    int center_X;
    int center_Y;
    int dimension;
    char name;
    bool *armor;

public:
    Ship(Coordinates first, Coordinates last){};   //to implement on Battle_Ship and Suppport_Ship
    Ship(Coordinates mono_Coord){}; //to implement on Submarine
    virtual void action(Coordinates first, Coordinates last) = 0;
    void reset_Armor(bool reset); 
};

#endif //LDP_BATTLESHIP_SHIP_H
