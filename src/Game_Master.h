//
// Created by Alessandra Villarà on 11/01/2023.
// matricola 1137125

#ifndef LDP_BATTLESHIP_GAME_MASTER_H
#define LDP_BATTLESHIP_GAME_MASTER_H

#include "Player.h"
#include "Com_Player.h"

class Game_Master {

private:

    Com_Player* Player2;
    Player*  Player1;
    int max_Turns;
    int current_Turn;
    std::string moves;
    Player* current_Turn_Player;

public:

    Game_Master(bool game_mode, int max=INT_MAX);
    bool Execute_Turn();
    void Execute_Special_Command(std::string);
    bool is_It_Endgame();

};
#endif //LDP_BATTLESHIP_GAME_MASTER_H
