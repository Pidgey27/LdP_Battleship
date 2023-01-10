//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#include "Player.h"
//search ship does first a search on the name, then on the coordinates. THe first instance searches for a match on center
//coordinates of the ship, then searches on the coordinates occupied by the ship.
int Player::search_For_Ship(Coordinates coord, char name) {
    name=toupper(name);      //turns name to upperCase, as default name for the ship is always on upperCase
    for(int i=0; i<pieces.size(); i++) {
        //search for center coordinates
        if (pieces[i]->get_Name() == name && pieces[i]->get_Center_X() == coord.get_X() &&
            pieces[i]->get_Center_Y() == coord.get_Y())
            return i;
        //search for with fixed x, builds the ship and verifies if any of the coordinates fits
        if (pieces[i]->get_Name() == name && pieces[i]->get_Center_X() == coord.get_X() && name != 'E') {
            std::cout<<"1)Verifico che il pezzo con centro in "<<Coordinates(pieces[i]->get_Center_X(), pieces[i]->get_Center_Y())<<std::endl;
            int j = pieces[i]->get_Center_Y() - ((pieces[i]->get_Dimension() - 1) / 2);
            int end = j + pieces[i]->get_Dimension();
            for (j; j <= end; j++)
                if (j == coord.get_Y())
                    return i;
        }
        //search for with fixed y, builds the ship and verifies if any of the coordinates fits
        if (pieces[i]->get_Name() == name && pieces[i]->get_Center_Y() == coord.get_Y() && name != 'E') {
            std::cout<<"2)Verifico che il pezzo con centro in "<<Coordinates(pieces[i]->get_Center_X(), pieces[i]->get_Center_Y())<<std::endl;
            int j = pieces[i]->get_Center_X() - ((pieces[i]->get_Dimension() - 1) / 2);
            int end = j + pieces[i]->get_Dimension();
            std::cout<<"cerco in "<< Coordinates(j, coord.get_Y())<<std::endl;
            for (j; j <= end; j++) {
                std::cout<<"cerco in "<< Coordinates(j, coord.get_Y())<<std::endl;
                if (j == coord.get_X())
                    return i;
            }
        }
    }
    throw std::runtime_error("Non ho trovato la nave richiesta, sono stati commessi degli errori!!!");
}

void Player::remove_Ship(int i) {
    pieces.erase(pieces.begin()+i);
}

Player::~Player() {
    pieces.clear();
}
Player::Player() {
    pieces.clear();
}

void Player::show_Pieces() {
    for(int i=0; i<pieces.size(); i++)
        std::cout<<pieces[i]->get_Name()<<" con centro in "<<Coordinates(pieces[i]->get_Center_X(), pieces[i]->get_Center_Y())<<std::endl;
}

