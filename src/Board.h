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
    
public:
    Board();
    Board(const Board& board)
        =delete;
    void operator=(const Board &) 
        =delete;

    /*Add a Battle_Ship type boat one the board while checking
    * for collision.
    * @param start first coordinate of the boat.
    * @param end last coordinate of the boat.
    */
    void addBattleShip(Coordinates start,Coordinates end);
    /*Add a Support_Ship type boat one the board while checking
    * for collision.
    * @param start first coordinate of the boat.
    * @param end last coordinate of the boat.
    */
    void addSupportShip(Coordinates start,Coordinates end);
    /*Add a Submarine type boat one the board while checking
    * for collision.
    * @param start first coordinate of the boat.
    */
    void addSubmarine(Coordinates start);
    /*
    *  Print all the board
    */
    void printBoard();
    /*
    * elimina nella tabella tutti i colpi assegnati
    */
   void clearHit();
    /*
    *elimina nella tabella i risultati dello scan
    */
   void clearScan();
    /*get the value at a particular coordinate
    * @param coor coordinate that you want to read.
    * @return char in the coordinate coor.
    */
   char get(Coordinates coor);
    /*
    *set a X char on a coordinate
    @param coor coordinate that you want to change.
    @return -false if it was an empty space
            -true if there was a ship
    */
   bool Shot(Coordinates coor);
    /*
    *set an area 5x5 to Y if there is some kind of ship
    @param coor coordinate that you want to control center of the area 5x5.
    @return -false if it was all empty space
            -true if there was at least one ship
    */
   bool Exploring(Coordinates coor);


    /*change the value at a particular coordinate in the attack board
    * @param coordinate coordinate that you want to change.
    * @param input value you want to assign to the coordinate spot .
    */
   void write_On_Attack_Board(Coordinates coordinate,char input);
    /*change the value at a particular coordinate in the defense board
    * @param coordinate coordinate that you want to change.
    * @param input value you want to assign to the coordinate spot .
    */
   void write_On_Defense_Board(Coordinates coordinate,char input);
    /*
    *print just defense board
    */
   void printDefBoard();
    /*
    *print just attack board
    */
   void printAtkBoard();

};
#endif //BOARD_H