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
    Com_Player*  Player1;
    int max_Turns;
    int current_Turn=1;
    std::string moves;
    Com_Player* current_Turn_Player=NULL;
    Com_Player* opponent=NULL;

public:

    Game_Master(bool game_mode, int max=INT_MAX);
    bool Execute_Turn();
    void Execute_Special_Command(std::string);
    bool is_It_Endgame();
    void fire_Protocol(Coordinates where_To_Fire);
    void who_Wins();
    bool ask_For_Coordinates();
    void exploring_Protocol(Coordinates coordinates);

};
#endif //LDP_BATTLESHIP_GAME_MASTER_H
