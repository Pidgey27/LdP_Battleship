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
            for (j; j <= end; j++) {
                if (j == coord.get_Y())
                    return i; }
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

//removes a dead ship from the vector containing them and updates the board removing the dead ship
void Player::remove_Ship(int j) {
    //to remove a battleship I have to construct it using its orientation, 0 for vertical, 1 for horyzonthal
    if(pieces[j]->get_Name()=='B') {
        if (pieces[j]->getDirection() == 0)
            for (int i = pieces[j]->get_Center_Y() - 2; i <= pieces[j]->get_Center_Y() + 2; i++)
                board->write_On_Defense_Board(Coordinates(pieces[j]->get_Center_X(), i), ' ');
        else {
            for (int i = pieces[j]->get_Center_X() - 2; i <= pieces[j]->get_Center_Y() + 2; i++)
                board->write_On_Defense_Board(Coordinates(i, pieces[j]->get_Center_Y()), ' ');
        }
        pieces.erase(pieces.begin()+j);
    }
    //to remove a SupportShip I have to construct it using its orientation, 0 for vertical, 1 for horyzonthal
    else if(pieces[j]->get_Name()=='S'){
        if(pieces[j]->getDirection() == 0)
            for(int i=pieces[j]->get_Center_Y()-1; i<=pieces[j]->get_Center_Y()+1; i++)
                board->write_On_Defense_Board(Coordinates(pieces[j]->get_Center_X(), i), ' ');
        else {
            for(int i=pieces[j]->get_Center_X()-1; i<=pieces[j]->get_Center_Y()+1; i++)
                board->write_On_Defense_Board(Coordinates(i, pieces[j]->get_Center_Y()), ' ');
        }
        pieces.erase(pieces.begin()+j);
    }
    //submarine occupies only one cell, so to delete if I just
    else if(pieces[j]->get_Name()=='E') {
        board->write_On_Defense_Board(Coordinates(pieces[j]->get_Center_X(), pieces[j]->get_Center_Y()), ' ');
        pieces.erase(pieces.begin()+j); }
}

Player::Player() {
}

//print every piece avaible
void Player::show_Pieces() {
    for(int i=0; i<pieces.size(); i++)
        std::cout<<pieces[i]->get_Name()<<" con centro in "<<Coordinates(pieces[i]->get_Center_X(), pieces[i]->get_Center_Y())<<std::endl;
}

//return 0 for battleship
//return 1 for submarine
//return 2 for support
//update coordinates for submarine and support, signaling their different power(respectively searching and healing), signals a shot
//on the other board for battleship
int Player::play(Coordinates coord_Ship_to_Move, Coordinates where_To_Move) {
    try {
        int index=search_For_Ship(coord_Ship_to_Move, board->get(coord_Ship_to_Move));
        pieces[index]->action(coord_Ship_to_Move, where_To_Move);
        if(pieces[index]->get_Name()=='B')
            return 0;
        else if(pieces[index]->get_Name()=='E') {
            update_Board(coord_Ship_to_Move, where_To_Move, index, 'E');
            return 1;
        }
        else if(pieces[index]->get_Name()=='S') {
            update_Board(coord_Ship_to_Move, where_To_Move, index, 'S');
            return 2;
        }
    throw std::invalid_argument("Inserita tra i pezzi del giocatore una nave sconosciuta! Non riconosco il nome del pezzo");
} catch(std::runtime_error &e) {
    std::cout<<"*Non ho trovato la nave inserita nelle prime coordinate inserite, controlla di avere inserito il centro"<<std::endl;
        throw std::runtime_error("C'è un carattere imprevisto sulla board, è stato compiuto qualche errore");
    }
}

//check in the board if there's an injured ship, and if there is one it heals it.
void Player::check_For_Healing(Coordinates coordinates) {
    for(int j=-1; j<2; j++) {
        for(int i=-1; i<2; i++) {
            if(board->get(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j))!=' ') {
                try {
                    int index= search_For_Ship(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j), board->get(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j)));
                    pieces[index]->reset_Armor(true);
                }catch (std::runtime_error &e) {
                    throw std::runtime_error("La Board non risulta aggiornata, correggere il programma");
                }
            }
        }
    }
}

//if there's not one piece left, declares endgame returning true
bool Player::check_For_Endgame() {
    if(pieces.size()==0)
        return true;
    else
        return false;
}

//this players board is under fire. if missed, returns false signaling miss; if hit, updates ship condition, and removes it
//if its dead
bool Player::under_Fire(Coordinates coord) {
    bool shot=board->get(coord)!=' ';
    int mid;
    if(!shot) {
        return false;
    }
    else {
        int injured= search_For_Ship(coord, board->get(coord));
        char temp;
        if(pieces[injured]->get_Name()=='B') {
            mid=2;
            temp='b';
        }
        if(pieces[injured]->get_Name()=='S') {
            mid = 1;
            temp = 's';
        }
        int where_hit;
        if(pieces[injured]->getDirection() == 0) {
            where_hit=pieces[injured]->get_Center_Y()-coord.get_Y()+mid;
            pieces[injured]->set_Injured(where_hit);
            board->write_On_Defense_Board(coord, temp);
        }
        if(pieces[injured]->getDirection() == 1){
            where_hit=pieces[injured]->get_Center_X()-coord.get_X()+mid;
            pieces[injured]->set_Injured(where_hit);
            board->write_On_Defense_Board(coord, temp);
            }
        if(pieces[injured]->isDead()){
            remove_Ship(injured);
        }
        return true;
    }
}

//removes spotted marks from attack board
void Player::remove_Spotted_Marks() {
    board->clearScan();
}

//prints defence board
void Player::print_Def_Board() {
    board->printDefBoard();
}

//prints attack board
void Player::print_Atk_Board() {
    board->printAtkBoard();
}

//erase every missed from attack board
void Player::erase_Missed_Atk() {
    board->clearHit();
}

//searches in defense board and returns its coordinates value. Used on architecture's upper level.
char Player::search_in_Def_Board(Coordinates coordinates) {
    return board->get(coordinates);
}

//writes in attack board a fixed char. Used on architecture's upper level.
void Player::write_in_Atk_Board(Coordinates coordinates, char name) {
    board->write_On_Attack_Board(coordinates, name);
}

Player::~Player() {
    pieces.clear();
}

//returns orientation for a single piece. Created for a test to check correct orientation return
bool Player::get_Orientation(int n) {
    return pieces[n]->getDirection();
}

//Prints a single ship in vector pieces, with int n as its index.
void Player::show_Ship(int n){
    std::cout<<"La nave richiesta e' una "<<pieces[n]->get_Name()<<" con centro in "<<Coordinates(pieces[n]->get_Center_X(), pieces[n]->get_Center_Y())<<std::endl;
}

//updates board after action. deletes previous coordinates in board, writes last in board.
void Player::update_Board(Coordinates first, Coordinates last, int index, char name) {
    if (name=='E') {
        board->write_On_Defense_Board(first, ' ');
        board->write_On_Defense_Board(last, 'E');
    }
    else if(name=='S'){
       if(pieces[index]->getDirection()==0) {
           for(int i=-1; i<2; i++) {
               board->write_On_Defense_Board(Coordinates(first.get_X(), first.get_Y()+i), ' ');
               board->write_On_Defense_Board(Coordinates(last.get_X(), last.get_Y()+i), 'E');
           }
       }
       else {
           for(int i=-1; i<2; i++) {
               board->write_On_Defense_Board(Coordinates(first.get_X()+i, first.get_Y()), ' ');
               board->write_On_Defense_Board(Coordinates(last.get_X()+i, last.get_Y()), 'E');
           }
       }
    }
}