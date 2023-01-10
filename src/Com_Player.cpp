//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125
#include "Com_Player.h"
#include "Player.h"
#include "Ship.h"

Coordinates Com_Player::get_First_Coordinate() {
    int n=rand() % pieces.size();
    return {pieces[n]->get_Center_X(), pieces[n]->get_Center_Y()};
}

Coordinates Com_Player::get_Second_Coordinate() {
    int x=rand()%12;
    int y=rand()%12;
    return {x, y};
}

Com_Player::Com_Player() {
    Coordinates prua("A6");
    Coordinates poppa("A10");
    pieces.emplace_back(new Battle_Ship(prua, poppa));
    pieces[0]->setName('S');
    pieces.emplace_back(new Battle_Ship(Coordinates("C1"), Coordinates("C5")));
    pieces[1]->setName('S');
    pieces.emplace_back(new Submarine(Coordinates("D5")));
    pieces[2]->setName('E');
}

std::string Com_Player::get_Coordinates_to_Move() {
    return get_First_Coordinate().to_String() + " " + get_Second_Coordinate().to_String();
}
