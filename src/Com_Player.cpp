//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125
#include "Com_Player.h"

Coordinates Com_Player::get_First_Coordinate() {
    int n=rand() % pieces.size();
    return Coordinates(pieces[n]->get_Center_X(), pieces[n]->get_Center_Y());
}

Coordinates Com_Player::get_Second_Coordinate() {
    int x=rand()%12;
    int y=rand()%12;
    return Coordinates(x, y).to_String();
}

Com_Player::Com_Player() {
    pieces.push_back(new Submarine(get_First_Coordinate()));
}
