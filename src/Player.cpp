//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#include "Player.h"
//search ship does first a search on the name, then on the coordinates. The first instance searches for a match on center
//coordinates of the ship, then searches on the coordinates occupied by the ship.
int Player::search_For_Ship(Coordinates coord, char name) {
    name=toupper(name);//turns name to upperCase, as default name for the ship is always on upperCase
    int dim;
    if(name=='b'|| name=='B')
        dim=5;
    if(name=='s'|| name=='S')
        dim=3;
    for(int i=0; i<pieces.size(); i++) {
        //search for center coordinates
        if (pieces[i]->get_Name() == name && pieces[i]->get_Center_X() == coord.get_X() &&
            pieces[i]->get_Center_Y() == coord.get_Y())
            return i;
        //search for with fixed x, builds the ship and verifies if any of the coordinates fits
        if (pieces[i]->get_Name() == name && pieces[i]->get_Center_X() == coord.get_X() && name != 'E') {
            int j = pieces[i]->get_Center_Y() - ((dim - 1) / 2);
            int end = j + dim;
            for (j; j <= end; j++)
                if (j == coord.get_Y())
                    return i;
        }
        //search for with fixed y, builds the ship and verifies if any of the coordinates fits
        if (pieces[i]->get_Name() == name && pieces[i]->get_Center_Y() == coord.get_Y() && name != 'E') {
            int j =(int) pieces[i]->get_Center_X() - ((dim - 1) / 2);
            int end = j + dim;
            for (j; j <= end; j++) {
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

Player::Player() {
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
    for(int j=-1; j<2; j++) {
        for(int i=-1; i<2; i++) {
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

bool Player::under_Fire(Coordinates coord) {
    bool shot=board->get(coord)!=' ';
    int mid;
    if(!shot)
        return false;
    else {
        int injured= search_For_Ship(coord, board->get(coord));
        if(pieces[injured]->get_Name()=='B')
            mid=2;
        if(pieces[injured]->get_Name()=='S')
            mid=1;
        int where_hit;
        if(pieces[injured]->get_Center_X()==coord.get_X()) {
            where_hit=pieces[injured]->get_Center_Y()-coord.get_Y()+mid;
            pieces[injured]->set_Injured(where_hit);
        }
        if(pieces[injured]->get_Center_Y()==coord.get_Y()){
            where_hit=pieces[injured]->get_Center_X()-coord.get_X()+mid;
            pieces[injured]->set_Injured(where_hit);
            if (pieces[injured]->isDead())
                pieces.erase(pieces.cbegin()+injured);
        }
        return true;
    }
}

void Player::remove_Spotted_Marks() {
    board->clearScan();
}

void Player::print_Def_Board() {
    board->printDefBoard();
}

void Player::print_Atk_Board() {
    board->printAtkBoard();
}

void Player::erase_Missed_Atk() {
    board->clearHit();
}

char Player::search_in_Def_Board(Coordinates coordinates) {
    return board->get(coordinates);
}

void Player::write_in_Atk_Board(Coordinates coordinates, char name) {

}

Player::~Player() {
    pieces.clear();
}
