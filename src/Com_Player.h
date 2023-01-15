//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#ifndef LDP_BATTLESHIP_COM_PLAYER_H
#define LDP_BATTLESHIP_COM_PLAYER_H

#include "Player.h"
#include <cstdlib>
#include <time.h>

class Com_Player: public Player {
private:
    Coordinates Randomly_get_Ship();
    Coordinates get_Real_Random_Coordinates();
    bool check_For_Valid_Coordinates();
    Coordinates Random_Coordinates_to_Construct_Ship(char name_ship, Coordinates first_coord);
    bool declare_Battleship();
    bool declare_Submarine();
    bool declare_SupportShip();

public:
    Com_Player();

    virtual ~Com_Player();

    std::string get_Coordinates_to_Move();
};

#endif //LDP_BATTLESHIP_COM_PLAYER_H
