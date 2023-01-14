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
    while(ask_For_Coordinates());
    // da inserire QUI la funzione per salvare in log;
    Coordinates first= Coordinates(moves.substr(0, moves.find_first_of(' ')));
    Coordinates second= Coordinates(moves.substr(moves.find_first_of(' '), moves.length()));
    int i=current_Turn_Player->play(first, second);
    if(i==0)
        fire_Protocol(second);
    //if(i==1)
        //set exploring protocol;
    if(i==2)
        current_Turn_Player->check_For_Healing(second);
    current_Turn++;
    return current_Turn==max_Turns || Player2->check_For_Endgame() || Player1->check_For_Endgame();
}

void Game_Master::who_Wins() {
    if(current_Turn==max_Turns)
        std::cout<<"Sono stati giocati "<<max_Turns<<", la partita è finita in parità"<<std::endl;
    if(Player1->check_For_Endgame())
        std::cout<<"Ha vinto il giocatore 2!!!"<<std::endl;
    if(Player2->check_For_Endgame())
        std::cout<<"Ha vinto il giocatore 1!!!"<<std::endl;
}

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
    if(shot)
        std::cout<<"Colpito!"<<std::endl;
    else
        std::cout<<"Buco nell'acqua"<<std::endl;
}

bool Game_Master::ask_For_Coordinates() {
    moves=current_Turn_Player->get_Coordinates_to_Move();
    if(moves.compare("AA AA")==0) {
        current_Turn_Player->remove_Spotted_Marks();
        return false;
    }
    if(moves.compare("XX XX")==0){
        return false;
    }
    return true;
}