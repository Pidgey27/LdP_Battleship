//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125
#include "Com_Player.h"
#include "Player.h"
#include "Ship.h"

Coordinates Com_Player::Randomly_get_Ship() {
    std::srand(time(NULL));
    int n=rand() % pieces.size();
    return {pieces[n]->get_Center_X(), pieces[n]->get_Center_Y()};
}

Coordinates Com_Player::get_Real_Random_Coordinates() {
    std::srand(time(NULL));
    int x=rand()%12;
    int y=rand()%12;
    return {x, y};
}

Com_Player::Com_Player() {
    Coordinates prua("A6");
    Coordinates poppa("A10");
    pieces.emplace_back(new Battle_Ship(prua, poppa));
    pieces.emplace_back(new Battle_Ship(Coordinates("C1"), Coordinates("C5")));
    pieces.emplace_back(new Submarine(Coordinates("D5")));
}

std::string Com_Player::get_Coordinates_to_Move() {
    //da implementare controllo su board!!
    return Randomly_get_Ship().to_String() + " " + get_Real_Random_Coordinates().to_String();
}

Coordinates Com_Player::Random_Coordinates_to_Construct_Ship(char name_ship, Coordinates first_coord) {
    std::srand(time(NULL));
    bool left_or_right=rand()%2;
    bool up_or_down=rand()%2;
    int dim;
    int x, y;
    if(name_ship=='S')
        dim=2;
    if(name_ship=='B')
        dim=4;
    if(left_or_right || first_coord.get_X()+dim<12)
        x=first_coord.get_X()+dim;
     else if(!left_or_right || first_coord.get_X()-dim>0)
        x=first_coord.get_X()-dim;
    if(up_or_down || first_coord.get_Y()+dim<12)
        y=first_coord.get_Y()+dim;
    else if(!up_or_down || first_coord.get_Y()-dim>0)
        y=first_coord.get_Y()-dim;
    try{
        Coordinates (x, y);
    }catch(std::invalid_argument &e) {
        Random_Coordinates_to_Construct_Ship(name_ship, first_coord);
    }
    return Coordinates(x,y);
}

