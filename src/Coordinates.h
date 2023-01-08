//
// Created by Aless on 21/12/2022.
//

#ifndef LDP_BATTLESHIP_COORDINATES_H
#define LDP_BATTLESHIP_COORDINATES_H
#include <iostream>
class Coordinates{
private:
    int coord_Y;
    int coord_X;
    //check 
    static void check_Invalid_Char(std::string yx);
    static std::string check_Lenght(std::string yx);
public:
    Coordinates(int x=0, int y=0) : coord_Y{y}, coord_X{x} {};
    Coordinates(std::string yx);
    int get_Y(){return coord_Y;};
    int get_X(){return coord_X;};
    std::string to_String();
    void set_X(int x){coord_X=x;};
    void set_Y(int y){coord_Y=y;};
};
std::ostream& operator <<(std::ostream& os, Coordinates coordinates);
#endif //LDP_BATTLESHIP_COORDINATES_H
