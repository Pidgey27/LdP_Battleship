//
// Created by Aless on 21/12/2022.
//

#ifndef LDP_BATTLESHIP_SHIP_H
#define LDP_BATTLESHIP_SHIP_H
#include "Coordinates.h"
class Ship {
protected:
    int center_X;
    int center_Y;
    char name;
    bool orientation; //0 for horizontal, 1 vertical
    bool armor[];   //the dimension of armor depends on the type of ship
public:
    Ship(Coordinates first, Coordinates last);  //to implement on Battle_Ship and Suppport_Ship
    Ship(Coordinates mono_Coord);   //to implement on Submarine
    virtual action(Coordinates first, Coordinates last);
    void reset_Armor();
};
#endif //LDP_BATTLESHIP_SHIP_H
