#include <iostream>
#include "Com_Player.h"
#include "tst/test_Com_Player.cpp"
#include "tst/test_board.cpp"
int main(int argc, char const *argv[])
{
    std::string uno = "A3";
    std::string due = "A7";
    std::string tre = "A2";
    Coordinates first(uno);
    Coordinates last(due);
    Coordinates ss(tre);
    //Submarine sb(ss);
    Battle_Ship bs (first ,last);
    std::cout << bs.getDirection() << bs.getCenter_X() << bs.getCenter_Y()<<std::endl;
    //std::cout << ss.get_X();

    std::cout << std::endl;
    //Testing Board
    //testBoard();
    test_Random_Get_Coordinates_to_Move();
    test_Dummy_Constructor_And_Search();
    return 0;
}





