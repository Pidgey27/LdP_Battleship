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
    /*
        Print the board
    */
    void printBoard();
    /*
        elimina nella tabella tutti i colpi assegnati
   */
   void clearHit();
    /*
        elimina nella tabella i risultati dello scan
   */
   void clearScan();
    /*
        get the value at a particular coordinate
   */
   char get(Coordinates coor);
    /*
        set a hit on a coordinate
    */
   void setHit(Coordinates coor);
   /*
        set a miss shot on a coordinate return:
    */
   void setMiss(Coordinates coor);

};
#endif //BOARD_H