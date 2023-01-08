/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#ifndef BOARD_H
#define BOARD_H
#include "Coordinates.h"
#include <iostream>

class Board {

private:

    char attackBoard[12][12];
    char defenseBoard[12][12];

    static Board* instancePtr;

    Board();
    void addBattleShip();

    public:
    Board(const Board& obj)
        =delete;
    static Board* getInstance(){
    if (instancePtr == NULL){
        instancePtr = new Board();
        return instancePtr;
    }
    else{
        return instancePtr;
    }

  }

    void printDefBoard();
    void printAtkBoard();
    void printBoard();

};

#endif //BOARD_H
