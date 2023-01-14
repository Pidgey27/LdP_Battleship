//
// Created by Alessandra Villarà on 21/12/2022
// matricola 1137125
//
#include "Coordinates.h"
#include <iostream>
#include <algorithm>
#include <string>

Coordinates::Coordinates(std::string yx) {
    check_Invalid_Char(yx);
    yx= check_Lenght(yx);
    if(yx.size() == 2) {
        coord_Y= yx[0] - 65;
        coord_X= yx[1] - 49;
    }
    if(yx.size() == 3){
        coord_Y= yx[0] - 65;
        coord_X= yx[2] - 49 + (yx[1] - 48)*10;
    }
    if(coord_Y > 12)
        coord_Y= coord_Y - 32;
    if(coord_Y > 11 || coord_X > 11 || coord_Y < 0 || coord_X < 0)
        throw std::runtime_error("Hai inserito delle coordinate invalide!");
}
//check input string for invalid char
void Coordinates::check_Invalid_Char(const std::string yx) {
    std::string invalid="!£$%&/()=?^[]{}*ç@°#§+*-_;,<>òàùèéçì|";
    if(yx.find_first_of(invalid) != std::string::npos)
        throw std::runtime_error("Hai inserito una stringa non valida!");
}
//method that remove all spaces from string, and then checks string lenght
std::string Coordinates::check_Lenght(std::string yx) {
    yx.erase(remove(yx.begin(), yx.end(), ' '), yx.end());
    if(yx.size() > 3)
        throw std::runtime_error("Hai inserito una stringa troppo lunga!");
    if(yx.size() < 2)
        throw std::runtime_error("Hai inserito una stringa troppo corta!");
    return yx;
}

std::string Coordinates::to_String() {
    char a= 'A' + coord_Y;
    return {a+std::to_string(coord_X+1)};
}

Coordinates::Coordinates(int x, int y) {
    if (x<0||y<0||x>11||y>11)
        throw std::invalid_argument("hai inserito coordinate fuori dalla board");
    coord_X=x;
    coord_Y=y;
}

std::ostream& operator <<(std::ostream& os, Coordinates coordinates) {
    return os<<coordinates.to_String();
}