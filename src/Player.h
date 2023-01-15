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
    std::vector<std::shared_ptr<Ship>> pieces;
    Board* board=Board::getInstance();
public:
    Player();
    int search_For_Ship(Coordinates coord, char name);
    virtual std::string get_Coordinates_to_Move() {return " ";};
    void remove_Ship(int i);
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
};
#endif