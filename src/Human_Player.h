/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#ifndef LDP_BATTLESHIP_HUMAN_PLAYER_H
#define LDP_BATTLESHIP_HUMAN_PLAYER_H

#include "Player.h"
#include <cstdlib>

class Human_Player: public Player {
private:
    int shipPosition[144] = {0};

    void addBattleShip(Coordinates start,Coordinates end);
    void addSupportShip(Coordinates start,Coordinates end);
    void addSubmarine(Coordinates start);

public:
    Human_Player();
    std::string get_Coordinates_to_Move();
    void prepareBoard(); 
};

#endif //LDP_BATTLESHIP_HUMAN_PLAYER_H