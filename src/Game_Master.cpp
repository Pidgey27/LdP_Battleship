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

