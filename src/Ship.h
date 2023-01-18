//
// Created by Alessandra Villarà on 21/12/2022
// matricola 1137125
//

#ifndef LDP_BATTLESHIP_SHIP_H
#define LDP_BATTLESHIP_SHIP_H
#include "Coordinates.h"
#include <cstring>
class Ship {

protected:
    bool orientation;   //1 for horizontal, 0 for vertical
    int center_X;
    int center_Y;
    int dimension;      //number of spaces occupied by the ship, used to construct it
    char name;          //letter to identify the ship (S for support_ship, E for Submarine, C for Battle_ship)
    bool *armor;

public:
    Ship() {
    name='B';
    }
    virtual void action(Coordinates first, Coordinates last)=0;
    virtual void reset_Armor(bool reset)=0;
    char get_Name(){ return name;}
    int get_Center_X(){return center_X;};
    int get_Center_Y(){return center_Y;};
    void set_Name(char n) { name=n;}
    void set_Injured(int n) { armor[n]=1;}
    virtual bool isDead()=0;
    virtual bool getDirection(){return orientation;}
    bool where_Hit(int n){};
    virtual ~Ship() {
    delete armor;
    }

};

#endif //LDP_BATTLESHIP_SHIP_H
