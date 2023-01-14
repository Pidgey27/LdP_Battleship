//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#include "Player.h"
//search ship does first a search on the name, then on the coordinates. The first instance searches for a match on center
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
            int j =(int) pieces[i]->get_Center_X() - ((pieces[i]->get_Dimension() - 1) / 2);
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
    //da implementare un remove from board per il pezzo
    pieces.erase(pieces.begin()+i);
}

Player::~Player() {
    pieces.clear();
    delete board;
}
Player::Player() {
    pieces.clear();
}

void Player::show_Pieces() {
    for(int i=0; i<pieces.size(); i++)
        std::cout<<pieces[i]->get_Name()<<" con centro in "<<Coordinates(pieces[i]->get_Center_X(), pieces[i]->get_Center_Y())<<std::endl;
}

//return 0 for battleship
//return 1 for submarine
//return 2 for support
//aggiorna le coordinate se in movimento o segnala che è stato sparato un colpo in base alla nave che si muove.
int Player::play(Coordinates coord_Ship_to_Move, Coordinates where_To_Move) {
    int index=search_For_Ship(coord_Ship_to_Move, board->get(coord_Ship_to_Move));
    pieces[index]->action(coord_Ship_to_Move, where_To_Move);
    if(board->get(coord_Ship_to_Move)=='B'||board->get(coord_Ship_to_Move)=='b')
        return 0;
    if(board->get(coord_Ship_to_Move)=='E')
        return 1;
    if(board->get(coord_Ship_to_Move)=='S'||board->get(coord_Ship_to_Move)=='s')
        return 2;
}

void Player::check_For_Healing(Coordinates coordinates) {
    for(int j=0; j<3; j++) {
        for(int i=0; i<3; i++) {
            if(board->get(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j))!=' ') {
                int index= search_For_Ship(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j), board->get(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j)));
                pieces[index]->reset_Armor(true);
            }
        }
    }
}

bool Player::check_For_Endgame() {
    if(pieces.size()==0)
        return true;
    else
        return false;
}
