//
// Created by Alessandra Villarà on 11/01/2023.
// matricola 1137125

#include "Game_Master.h"

Game_Master::Game_Master(bool game_mode, int max) {
    max_Turns=max;
    if(game_mode) {
        Player1= new Com_Player();  //in questo modo si carica automaticamente il costruttore per ogni nave del gioco
        Player2=new Com_Player();
    }
    else {
        //Player1=new Human_Player();   Da implementare
        Player2=new Com_Player();
    }
}

//method uses to actually play
//false until you reach the maximum number of turns, or one of the player loses all ships
bool Game_Master::Execute_Turn() {
    if(current_Turn%2==0) {
        current_Turn_Player = Player2;
        opponent=Player1;
    }
    else {
        current_Turn_Player = Player1;
        opponent=Player2;
    }
    while(!ask_For_Coordinates());
    // da inserire QUI la funzione per salvare in log;
    Coordinates first= Coordinates(moves.substr(0, moves.find_first_of(' ')));
    Coordinates second= Coordinates(moves.substr(moves.find_first_of(' '), moves.length()));
    int i=current_Turn_Player->play(first, second);
    if(i==0)
        fire_Protocol(second);
    if(i==1)
        exploring_Protocol(second);
    if(i==2)
        current_Turn_Player->check_For_Healing(second);
    current_Turn++;
    return current_Turn==max_Turns || Player2->check_For_Endgame() || Player1->check_For_Endgame();
}

//method that says who wins the game
void Game_Master::who_Wins() {
    if(current_Turn==max_Turns)
        std::cout<<"*Sono stati giocati "<<max_Turns<<", la partita è finita in parità"<<std::endl;
    if(Player1->check_For_Endgame())
        std::cout<<"*Ha vinto il giocatore 2!!!"<<std::endl;
    if(Player2->check_For_Endgame())
        std::cout<<"*Ha vinto il giocatore 1!!!"<<std::endl;
}

//method that implements firing on pieces, eliminates the piece if armour is destroyed
void Game_Master::fire_Protocol(Coordinates where_To_Fire) {
    if(current_Turn%2==0){
        current_Turn_Player=Player2;
        opponent=Player1;
    }
    else {
        current_Turn_Player = Player1;
        opponent = Player2;
    }
    bool shot=opponent->under_Fire(where_To_Fire);
    if(shot) {
        std::cout << "*Colpito!" << std::endl;
        current_Turn_Player->write_in_Atk_Board(where_To_Fire, 'X');
    }
    else {
        std::cout << "*Buco nell'acqua" << std::endl;
        current_Turn_Player->write_in_Atk_Board(where_To_Fire, 'O');
    }
}

//method that implements special commands, like show def board, remove spotted or remove missed on attack board
bool Game_Master::ask_For_Coordinates() {
    moves=current_Turn_Player->get_Coordinates_to_Move();
    if(moves=="AA AA") {
        current_Turn_Player->remove_Spotted_Marks();
        return false;
    }
    if(moves=="XX XX"){
        current_Turn_Player->print_Def_Board();
        return false;
    }
    if(moves=="OO OO"){
        current_Turn_Player->erase_Missed_Atk();
    }
    return true;
}

//method to implement exploring for submarine
void Game_Master::exploring_Protocol(Coordinates coordinates) {
    for(int i=-2; i<3; i++){
        for(int j=-2; j<3; j++) {
            if(opponent->search_in_Def_Board(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j))!=' ')
                current_Turn_Player->write_in_Atk_Board(Coordinates(coordinates.get_X()+i, coordinates.get_Y()+j), 'Y');
        }
    }
}

