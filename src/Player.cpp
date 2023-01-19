//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#include "Player.h"

Player::Player() {
}
//search ship does first a search on the name, then on the coordinates. The first instance searches for a match on center
//coordinates of the ship, then searches on the coordinates occupied by the ship.
int Player::search_For_Ship(Coordinates coord) {
    int dim;
    if (board.get(coord) == 'C' || board.get(coord) == 'C') {
        dim = 2;
        for (int i = 0; i < battleship.size(); i++) {
            if (battleship.at(i).get_Center_X() == coord.get_X() &&
                battleship.at(i).get_Center_Y() == coord.get_Y())
                return i;
            if (battleship.at(i).getDirection() == 0) {
                for (int j = battleship.at(i).get_Center_Y() - dim; j <= battleship.at(i).get_Center_Y() + i; j++) {
                    if (j == coord.get_Y())
                        return i;
                }
            }
            if (battleship.at(i).getDirection() == 1) {
                for (int k = battleship.at(i).get_Center_X(); k <= battleship.at(i).get_Center_X() + dim; k++) {
                    if (k == coord.get_X())
                        return i;
                }
            }
        }
    } else if (board.get(coord) == 'S' || board.get(coord) == 's') {
        dim = 1;
        for (int i = 0; i < support.size(); i++) {
            if (support.at(i).get_Center_X() == coord.get_X() &&
                support.at(i).get_Center_Y() == coord.get_Y())
                return i;
            if (support.at(i).getDirection() == 0) {
                for (int j = support.at(i).get_Center_Y() - dim; j <= support.at(i).get_Center_Y() + i; j++) {
                    if (j == coord.get_Y())
                        return i;
                }
            }
            if (support.at(i).getDirection() == 1) {
                for (int k = support.at(i).get_Center_X(); k <= support.at(i).get_Center_X() + dim; k++) {
                    if (k == coord.get_X())
                        return i;
                }
            }
        }
    } else if (board.get(coord) == 'E') {
        for (int i = 0; i < submarine.size(); i++) {
            if (support.at(i).get_Center_X() == coord.get_X() &&
                support.at(i).get_Center_Y() == coord.get_Y())
                return i;
        }
    }
    else
        throw std::runtime_error("Non ho trovato la nave richiesta, il carattere preso dalla board!!!");
}

//print every piece avaible
void Player::show_Pieces() {
    for (int i = 0; i <battleship.size(); i++) {
        std::cout << battleship.at(i).get_Name()<< " con centro in "
                  << Coordinates(battleship.at(i).get_Center_X(), battleship.at(i).get_Center_Y()) << std::endl;
    }
    for (int i = 0; i <support.size(); i++) {
        std::cout << support.at(i).get_Name()<< " con centro in "
                  << Coordinates(support.at(i).get_Center_X(), support.at(i).get_Center_Y()) << std::endl;
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
        if(n=='C'||n=='c') {
            battleship.at(index).action(coord_Ship_to_Move, where_To_Move);
            return 0;
        }
        else if(n=='S'|| n=='s') {
            support.at(index).action(coord_Ship_to_Move, where_To_Move);
            update_Board(coord_Ship_to_Move, where_To_Move, index);
            return 1;
        }
        else if(n=='E') {
            submarine.at(index).action(coord_Ship_to_Move, where_To_Move);
            update_Board(coord_Ship_to_Move, where_To_Move, index);
            return 2;
        }
        else
    throw std::invalid_argument("Inserita tra i pezzi del giocatore una nave sconosciuta! Non riconosco il nome del pezzo");
} catch(std::runtime_error &e) {
    std::cout<<"*Non ho trovato la nave inserita nelle prime coordinate inserite, controlla di avere inserito il centro"<<std::endl;
        throw std::runtime_error("C'è un carattere imprevisto sulla board, è stato compiuto qualche errore");
    }
}

//check in the board if there's an injured ship, and if there is one it heals it.
void Player::check_For_Healing(Coordinates coordinates) {
    int sup = search_For_Ship(coordinates);
    for (int j = coordinates.get_Y() - 1; j < coordinates.get_Y() + 2; j++) {
        if (j < 0)
            j=0;
        else if (j > 12)
            return;
        else {
            for (int i =coordinates.get_X() -1; i < coordinates.get_X()+2; i++) {
                if (i < 0)
                    i=0;
                else if (i > 12)
                    return;
                else {
                    if(board.get(Coordinates(i, j)) != ' ') {
                        if (board.get(Coordinates(i, j)) == 'S'||board.get(Coordinates(i, j)) == 's') {
                            try {
                                int index = search_For_Ship(Coordinates(i, j));
                                if (sup != index)
                                    support.at(index).reset_Armor(true);
                            } catch (std::runtime_error &e) {
                            }
                        }
                        else if (board.get(Coordinates(i, j)) == 'C'||board.get(Coordinates(i, j)) == 'c') {
                            try {
                                int index = search_For_Ship(Coordinates(i, j));
                                battleship.at(index).reset_Armor(true);
                            } catch (std::runtime_error &e) {
                            }
                        }
                        else  {
                            //do nothing
                        }
                    }
                }
            }
        }
    }
}

//if there's not one piece left, declares endgame returning true
bool Player::check_For_Endgame() {
    if(support.size()==0 && submarine.size()==0 && battleship.size()==0)
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
        char temp=board.get(coord);
        int where_hit;
        if(temp=='C') {
            mid = 2;
            if(battleship.at(injured).getDirection() == 0) {
                where_hit=coord.get_Y()-battleship.at(injured).get_Center_Y()+mid;
                battleship.at(injured).set_Injured(where_hit);
                board.write_On_Defense_Board(coord, 'c');
            }
            if(battleship.at(injured).getDirection() == 1){
                where_hit=coord.get_X()+mid-battleship.at(injured).get_Center_X();
                battleship.at(injured).set_Injured(where_hit);
                board.write_On_Defense_Board(coord, 'c');
            }
        }
        if(temp=='S')
            mid = 1;
        if(support.at(injured).getDirection() == 0) {
            where_hit=coord.get_Y()-support.at(injured).get_Center_Y()+mid;
            support.at(injured).set_Injured(where_hit);
            board.write_On_Defense_Board(coord, 's');
        }
        if(support.at(injured).getDirection() == 1){
            where_hit=coord.get_X()+mid-support.at(injured).get_Center_X();
            support.at(injured).set_Injured(where_hit);
            board.write_On_Defense_Board(coord, 's');
        }
        if(temp=='E') {
            submarine.erase(submarine.cbegin()+injured);
            board.write_On_Defense_Board(coord, ' ');
        }
        if(battleship.at(injured).isDead()){
            remove_Ship(injured, 'C');
        }
        if(support.at(injured).isDead())
            remove_Ship(injured, 'S');
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

//returns orientation for a single piece. Created for a test to check correct orientation return
bool Player::get_Orientation(int n, char name) {
    if(name=='C')
        return battleship.at(n).getDirection();
    else
        return support.at(n).getDirection();
}

//Prints a single ship in vector pieces, with int n as its index.
void Player::show_Ship(int n, char name){
    if(name=='C')
    std::cout<<"La nave richiesta e' una "<<battleship.at(n).get_Name()<<" con centro in "<<Coordinates(battleship.at(n).get_Center_X(), battleship.at(n).get_Center_Y())<<std::endl;
    else if(name=='S')
        std::cout<<"La nave richiesta e' una "<<support.at(n).get_Name()<<" con centro in "<<Coordinates(support.at(n).get_Center_X(), support.at(n).get_Center_Y())<<std::endl;
    else
    if(name=='E')
        std::cout<<"La nave richiesta e' una "<<submarine.at(n).get_Name()<<" con centro in "<<Coordinates(submarine.at(n).get_Center_X(), submarine.at(n).get_Center_Y())<<std::endl;

}

//updates board after action. deletes previous coordinates in board, writes last in board.
void Player::update_Board(Coordinates first, Coordinates last, int index) {
    if (board.get(first)=='E') {
        board.write_On_Defense_Board(first, ' ');
        board.write_On_Defense_Board(last, 'E');
    }
    else if(board.get(first)=='S'|| board.get(first)=='s'){
       if(support.at(index).getDirection()==0) {
           for(int i=-1; i<2; i++) {
               board.write_On_Defense_Board(Coordinates(first.get_X(), first.get_Y()+i), ' ');
               if(support.at(index).where_Hit(i+1)==0)
                   board.write_On_Defense_Board(Coordinates(last.get_X(), last.get_Y()+i), 'S');
               else
                   board.write_On_Defense_Board(Coordinates(last.get_X(), last.get_Y()+i), 's');

           }
       }
       else {
           for(int i=-1; i<2; i++) {
               board.write_On_Defense_Board(Coordinates(first.get_X()+i, first.get_Y()), ' ');
               if(support.at(index).where_Hit(i+1)==1)
                   board.write_On_Defense_Board(Coordinates(last.get_X()+i, last.get_Y()), 's');
               else
                   board.write_On_Defense_Board(Coordinates(last.get_X()+i, last.get_Y()), 'S');

           }
       }
    }
}
//removes a dead ship from the vector containing them and updates the board removing the dead ship
void Player::remove_Ship(int j, char name) {
    //to remove a battleship I have to construct it using its orientation, 0 for vertical, 1 for horyzonthal
    int dim;
    if(name=='C') {
        dim = 2;
        if (battleship.at(j).getDirection() == 0)
            for (int i =battleship.at(j).get_Center_Y() - dim; i <= battleship.at(j).get_Center_Y() + dim; i++)
                board.write_On_Defense_Board(Coordinates(battleship.at(j).get_Center_X(), i), ' ');
        else {
            for (int i = battleship.at(j).get_Center_X() - dim; i <= battleship.at(j).get_Center_Y() + dim; i++)
                board.write_On_Defense_Board(Coordinates(i, battleship.at(j).get_Center_Y()), ' ');
        }
    }
    else if(name=='S') {
            dim = 1;
            if (support.at(j).getDirection() == 0)
                for (int i =support.at(j).get_Center_Y() - dim; i <= support.at(j).get_Center_Y() + dim; i++)
                    board.write_On_Defense_Board(Coordinates(support.at(j).get_Center_X(), i), ' ');
            else {
                for (int i = support.at(j).get_Center_X() - dim; i <= support.at(j).get_Center_Y() + dim; i++)
                    board.write_On_Defense_Board(Coordinates(i, support.at(j).get_Center_Y()), ' ');
            }
        }
    else {
        board.write_On_Defense_Board(Coordinates(submarine.at(j).get_Center_X(), submarine.at(j).get_Center_Y()), ' ');
        submarine.erase(submarine.begin()+j); }
}
