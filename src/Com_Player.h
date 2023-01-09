//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#ifndef LDP_BATTLESHIP_COM_PLAYER_H
#define LDP_BATTLESHIP_COM_PLAYER_H

#include "Player.h"

class Com_Player: protected Player {
private:
    Coordinates get_First_Coordinate();
    Coordinates get_Second_Coordinate();
    bool check_For_Valid_Coordinates();

public:
    Com_Player();
    std::string get_Coordinates_to_Move();

};

#endif //LDP_BATTLESHIP_COM_PLAYER_H
