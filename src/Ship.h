//
// Created by Alessandra Villarà on 21/12/2022
// matricola 1137125
//

#ifndef LDP_BATTLESHIP_SHIP_H
#define LDP_BATTLESHIP_SHIP_H
#include "Coordinates.h"

class Ship {

protected:
    bool orientation;   //0 for horizontal, 1 for vertical
    int center_X;
    int center_Y;
    int dimension;      //number of spaces occupied by the ship, used to construct it
    char name;          //letter to identify the ship (S for support_ship, E for Submarine, C for Battle_ship)
    bool *armor;

public:
    Ship(Ship&&)=delete;
    Ship(Ship const&)= delete;
    Ship(Coordinates first, Coordinates last){};   //to implement on Battle_Ship and Suppport_Ship
    Ship(Coordinates mono_Coord){}; //to implement on Submarine
    virtual void action(Coordinates first, Coordinates last) {};
    void reset_Armor(bool reset);
    char get_Name(){ return name;}
    int get_Center_X() {return center_X;}
    int get_Center_Y() { return center_Y;}
    int get_Dimension() {return dimension;}
    bool get_Orientation() {return orientation;}
    void setName(char n) { name=n;}
    void set_Center_X(int x) { center_X=x;}
    void set_Center_Y(int y) { center_Y=y;}
};
static std::ostream& operator <<(std::ostream& os, Ship ship) {
    return os<<ship.get_Name()<<" with center in "<<Coordinates(ship.get_Center_X(), ship.get_Center_Y());
}

#endif //LDP_BATTLESHIP_SHIP_H
