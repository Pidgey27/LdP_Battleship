//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#ifndef LDP_BATTLESHIP_PLAYER_H
#define LDP_BATTLESHIP_PLAYER_H

#include "Ship.h"
#include "Submarine.h"
#include "Support_Ship.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <memory>

class Player {
protected:
    std::string name;
    std::vector<Battle_Ship> battleship;
    std::vector<Submarine> submarine;
    std::vector<Support_Ship> support;
    Board board;
    void remove_Ship(int i, char name);
    void update_Board(Coordinates first, Coordinates last, int index);

public:

    Player();
    virtual ~Player();
    std::string get_Coordinates_to_Move() {};
    int search_For_Ship(Coordinates coord);
    int play(Coordinates coord_Ship_to_Move, Coordinates where_To_Move);
    void check_For_Healing(Coordinates coordinates);
    void show_Pieces();
    bool check_For_Endgame();
    bool under_Fire(Coordinates coord);
    void remove_Spotted_Marks();
    void print_Def_Board();
    void print_Atk_Board();
    void erase_Missed_Atk();
    char search_in_Def_Board(Coordinates coordinates);
    void write_in_Atk_Board(Coordinates coordinates, char name);
    bool get_Orientation(int n, char name);
    void show_Ship(int n , char name);
    std::string get_Name(){return name;}

};
#endif