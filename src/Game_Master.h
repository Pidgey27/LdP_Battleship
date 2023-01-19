//
// Created by Alessandra Villarà on 11/01/2023.
// matricola 1137125

#ifndef LDP_BATTLESHIP_GAME_MASTER_H
#define LDP_BATTLESHIP_GAME_MASTER_H

#include "Player.h"
#include "Com_Player.h"
#include "Human_Player.h"
class Game_Master {

private:

    Player* Player2;
    Com_Player*  Player1;
    int max_Turns;
    int current_Turn=1;
    std::string moves;
    Player* current_Turn_Player=NULL;
    Player* opponent=NULL;

public:

    Game_Master(bool game_mode, int max=2147483647);
    Game_Master(std::vector<std::string> coord_P1, std::vector<std::string> coord_P2);
    bool Execute_Turn();
    void Execute_Turn_Replay(std::string mossa);
    bool is_It_Endgame();
    void fire_Protocol(Coordinates where_To_Fire);
    void who_Wins();
    bool ask_For_Coordinates();
    void exploring_Protocol(Coordinates coordinates);
    bool ask_For_Coordinates_Replay(std::string mossa);
};
#endif //LDP_BATTLESHIP_GAME_MASTER_H
