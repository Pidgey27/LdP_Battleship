/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "src\Board.h"

static void testBoard(){
    Board* test = Board::getInstance();
    test->printBoard();


    std::cout << "all test are successfull";
}