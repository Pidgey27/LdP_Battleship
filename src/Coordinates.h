//
// Created by Aless on 21/12/2022.
//

#ifndef LDP_BATTLESHIP_COORDINATES_H
#define LDP_BATTLESHIP_COORDINATES_H
#include <iostream>
class Coordinates{
protected:
    int coord_Y;
    int coord_X;
public:
    Coordinates(int x, int y) : coord_Y{y}, coord_X{x} {};
    Coordinates(std::string yx);
    int get_X(){return coord_Y;};
    int get_Y(){return coord_X;};
    static void check_Invalid_Char(std::string yx);
    static std::string check_Lenght(std::string yx);
    std::string to_String();
};
std::ostream& operator <<(std::ostream& os, Coordinates coordinates);
#endif //LDP_BATTLESHIP_COORDINATES_H
