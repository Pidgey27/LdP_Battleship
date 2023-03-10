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
    Coordinates temp1; //coordinata più piccola
    Coordinates temp2; //coordinata più grande
    void Randomly_get_Ship();    //usa temp1
    void get_Real_Random_Coordinates(); //usa temp1
    bool check_For_Valid_Coordinates();
    void Random_Coordinates_to_Construct_Ship(char name_ship, Coordinates first_coord); //usa temp2
    bool declare_Battleship();
    bool declare_Submarine();
    bool declare_SupportShip();
    void order_Coord();
public:
    Com_Player();

    std::string get_Coordinates_to_Move();

    ~Com_Player() override;
};

#endif //LDP_BATTLESHIP_COM_PLAYER_H
