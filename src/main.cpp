#include "Battle_Ship.h"
#include <iostream>
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
    std::cout << bs.getDirection() << bs.getCenter_X() << bs.getCenter_Y();
    //std::cout << ss.get_X();

    std::cout << std::endl;
    //Testing Board
    testBoard();
    //std::cout << "\033[1;31mbold red text\033[0m\n";

    return 0;
}
