/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "src\Board.h"

static void testBoard(){
    //Battle_Ship nave = Battle_Ship(Coordinates("h1"),Coordinates("n1"));

    bool check = true;
    Board* test = Board::getInstance();
    Board* test2 = Board::getInstance();
    
    test->printBoard();


    if(check)
        std::cout << "all test are successfull";
}