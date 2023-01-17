/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#ifndef LDP_BATTLESHIP_HUMAN_PLAYER_H
#define LDP_BATTLESHIP_HUMAN_PLAYER_H

#include "Player.h"
#include <cstdlib>

class Human_Player: public Player {
private:
    void prepareBoard();
    bool checkBattleShip(Coordinates first, Coordinates last);
    bool checkSupportShip(Coordinates first, Coordinates last);
    //bool checkBattleShip(Coordinates first, Coordinates last);
public:
    Human_Player();
    virtual ~Human_Player();
    std::string get_Coordinates_to_Move();
    
};

#endif //LDP_BATTLESHIP_HUMAN_PLAYER_H