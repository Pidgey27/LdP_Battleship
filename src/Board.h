/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "Coordinates.h"
#include "Battle_Ship.h"

class Board {

private:
    char attackBoard[12][12];
    char defenseBoard[12][12];
    static Board* instancePtr;

    Board();
public:

    Board(const Board& board)
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
    void addBattleShip(Coordinates start,Coordinates end);
    void addSupportShip(Coordinates start,Coordinates end);
    void addSubmarine(Coordinates start);

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
   /*bool Shot(Coordinates coor);
   bool Exploring(Coordinates coor);*/
   void write_On_Attack_Board(Coordinates coordinate,char input);
   void write_On_Defense_Board(Coordinates coordinate,char input);
   void printDefBoard();
   void printAtkBoard();

};
#endif //BOARD_H