/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "Coordinates.h"

class Board {

private:
    char attackBoard[12][12];
    char defenseBoard[12][12];
    static Board* instancePtr;

    Board();
    void addBattleShip(int i);
    void addSupportShip(int i);
    void addSubmarine(int i);
    void prepareBoard();
    void printDefBoard();
    void printAtkBoard();

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

    void printBoard();
    //TODO
    /*
    CLEAR "Y" from attack
    CLEAR "O" from attack 
    OUTPUT COORDINATA
    HIT write something in table
    IS EMPTY (C'E " " NELLA COORDINATA)  ???
    */


};
#endif //BOARD_H
