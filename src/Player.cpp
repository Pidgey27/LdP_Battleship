//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#include "Player.h"

//search ship does first a search on the name, then on the coordinates. The first instance searches for a match on center
//coordinates of the ship, then searches on the coordinates occupied by the ship.
int Player::search_For_Ship(Coordinates coord) {
    int dim;
    for(int i=0; i<pieces.size(); i++) {
        if(pieces.at(i)->get_Name()=='C')
            dim=5;
        if(pieces.at(i)->get_Name()=='S')
            dim=3;
        //search for center coordinates
        if (pieces.at(i)->get_Center_X() == coord.get_X() && pieces.at(i)->get_Center_Y() == coord.get_Y())
            return i;
        //search for with fixed x, builds the ship and verifies if any of the coordinates fits
        if (pieces.at(i)->getDirection() == 0  && pieces.at(i)->get_Name()!= 'E') {
            int j = pieces.at(i)->get_Center_Y() - ((dim - 1) / 2);
            int end = j + dim;
            for (j; j <= end; j++) {
                if (j == coord.get_Y())
                    return i; }
        }
        //search for with fixed y, builds the ship and verifies if any of the coordinates fits
        if (pieces.at(i)->getDirection() == 1 && pieces.at(i)->get_Name()!= 'E') {
            int k =(int) pieces.at(i)->get_Center_X() - ((dim - 1) / 2);
            int end = k + dim;
            for (k; k <= end; k++) {
                if (k == coord.get_X())
                    return i;
            }
        }
    }
    throw std::runtime_error("Non ho trovato la nave richiesta, sono stati commessi degli errori!!!");
}

//removes a dead ship from the vector containing them and updates the board removing the dead ship
void Player::remove_Ship(int j) {
    //to remove a battleship I have to construct it using its orientation, 0 for vertical, 1 for horyzonthal
    int dim;
    if(pieces.at(j)->get_Name()=='C')
        dim=2;
    else if(pieces.at(j)->get_Name()=='S')
        dim=1;
    if(pieces.at(j)->get_Name()!='E') {
        if (pieces.at(j)->getDirection() == 0)
            for (int i = pieces.at(j)->get_Center_Y() - dim; i <= pieces.at(j)->get_Center_Y() + dim; i++)
                board.write_On_Defense_Board(Coordinates(pieces.at(j)->get_Center_X(), i), ' ');
        else {
            for (int i = pieces.at(j)->get_Center_X() - dim; i <= pieces.at(j)->get_Center_Y() + dim; i++)
                board.write_On_Defense_Board(Coordinates(i, pieces.at(j)->get_Center_Y()), ' ');
        }
        pieces.erase(pieces.begin() + j);
    }
    else {
        board.write_On_Defense_Board(Coordinates(pieces.at(j)->get_Center_X(), pieces.at(j)->get_Center_Y()), ' ');
        pieces.erase(pieces.begin()+j); }
}

Player::Player() {
}

//print every piece avaible
void Player::show_Pieces() {
    for (int i = 0; i <pieces.size(); i++) {
        std::cout << pieces.at(i)->get_Name() << " con centro in "
                  << Coordinates(pieces.at(i)->get_Center_X(), pieces.at(i)->get_Center_Y()) << std::endl;
    }
}

//return 0 for battleship
//return 1 for submarine
//return 2 for support
//update coordinates for submarine and support, signaling their different power(respectively searching and healing), signals a shot
//on the other board for battleship
int Player::play(Coordinates coord_Ship_to_Move, Coordinates where_To_Move) {
    char n=board.get(coord_Ship_to_Move);
    try {
        int index=search_For_Ship(coord_Ship_to_Move);
        pieces.at(index)->action(coord_Ship_to_Move, where_To_Move);
        if(n=='C'||n=='c')
            return 0;
        else if(n=='E') {
            update_Board(coord_Ship_to_Move, where_To_Move, index);
            return 1;
        }
        else if(n=='S'|| n=='s') {
            update_Board(coord_Ship_to_Move, where_To_Move, index);
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
    int sub = search_For_Ship(coordinates);
    for (int j = coordinates.get_Y() - 1; j < coordinates.get_Y() + 2; j++) {
        if (j < 0)
            j++;
        else if (j > 12)
            return;
        else {
            for (int i =coordinates.get_X() -1; i < coordinates.get_X()+2; i++) {
                if (i < 0)
                    i++;
                else if (i > 12)
                    return;
                else {
                    if(board.get(Coordinates(i, j)) != ' '){
                        try {
                            int index = search_For_Ship(Coordinates(i, j));
                            if (sub != index)
                                pieces.at(index)->reset_Armor(true);
                        } catch (std::runtime_error &e) {
                        }
                    }
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
    bool shot=board.get(coord)!=' ';
    int mid;
    if(!shot) {
        return false;
    }
    else {
        int injured= search_For_Ship(coord);
        char temp=pieces.at(injured)->get_Name();
        if(temp=='C')
            mid=2;
        if(temp=='S')
            mid = 1;
        if(temp=='E')
            mid=0;
        tolower(temp);
        int where_hit;
        if(pieces.at(injured)->getDirection() == 0) {
            where_hit=coord.get_Y()-pieces.at(injured)->get_Center_Y()+mid;
            pieces.at(injured)->set_Injured(where_hit);
            board.write_On_Defense_Board(coord, temp);
        }
        if(pieces.at(injured)->getDirection() == 1){
            where_hit=coord.get_X()+mid-pieces.at(injured)->get_Center_X();
            pieces.at(injured)->set_Injured(where_hit);
            board.write_On_Defense_Board(coord, temp);
            }
        if(pieces.at(injured)->isDead()){
            remove_Ship(injured);
        }
        return true;
    }
}

//removes spotted marks from attack board
void Player::remove_Spotted_Marks() {
    board.clearScan();
}

//prints defence board
void Player::print_Def_Board() {
    board.printDefBoard();
}

//prints attack board
void Player::print_Atk_Board() {
    board.printAtkBoard();
}

//erase every missed from attack board
void Player::erase_Missed_Atk() {
    board.clearHit();
}

//searches in defense board and returns its coordinates value. Used on architecture's upper level.
char Player::search_in_Def_Board(Coordinates coordinates) {
    return board.get(coordinates);
}

//writes in attack board a fixed char. Used on architecture's upper level.
void Player::write_in_Atk_Board(Coordinates coordinates, char name) {
    board.write_On_Attack_Board(coordinates, name);
}

Player::~Player() {
    pieces.clear();
}

//returns orientation for a single piece. Created for a test to check correct orientation return
bool Player::get_Orientation(int n) {
    return pieces.at(n)->getDirection();
}

//Prints a single ship in vector pieces, with int n as its index.
void Player::show_Ship(int n){
    std::cout<<"La nave richiesta e' una "<<pieces.at(n)->get_Name()<<" con centro in "<<Coordinates(pieces.at(n)->get_Center_X(), pieces.at(n)->get_Center_Y())<<std::endl;
}

//updates board after action. deletes previous coordinates in board, writes last in board.
void Player::update_Board(Coordinates first, Coordinates last, int index) {
    if (board.get(first)=='E') {
        board.write_On_Defense_Board(first, ' ');
        board.write_On_Defense_Board(last, 'E');
    }
    else if(board.get(first)=='S'|| board.get(first)=='s'){
       if(pieces.at(index)->getDirection()==0) {
           for(int i=-1; i<2; i++) {
               board.write_On_Defense_Board(Coordinates(first.get_X(), first.get_Y()+i), ' ');
               if(pieces.at(index)->where_Hit(i+1)==0)
                   board.write_On_Defense_Board(Coordinates(last.get_X(), last.get_Y()+i), 'S');
               else
                   board.write_On_Defense_Board(Coordinates(last.get_X(), last.get_Y()+i), 's');

           }
       }
       else {
           for(int i=-1; i<2; i++) {
               board.write_On_Defense_Board(Coordinates(first.get_X()+i, first.get_Y()), ' ');
               if(pieces.at(index)->where_Hit(i+1)==1)
                   board.write_On_Defense_Board(Coordinates(last.get_X()+i, last.get_Y()), 's');
               else
                   board.write_On_Defense_Board(Coordinates(last.get_X()+i, last.get_Y()), 'S');

           }
       }
    }
}