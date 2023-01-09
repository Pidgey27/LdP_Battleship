//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#include "Ship.h"
#include "Battle_Ship.h"
#include "Submarine.h"
#include "Support_Ship.h"
#include "Board.h"
#include <iostream>
#include <vector>

class Player {
protected:
    std::vector<Ship> pieces;
public:
    Player();
    int search_For_Ship(Coordinates coord, char name);
    std::string get_Coordinates_to_Move();
    void remove_Ship(int i);
    int play(Coordinates coord_Ship_to_Move, Coordinates where_To_Move);
    void check_For_Healing(Coordinates coordinates);
};