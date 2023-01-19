//
// Created by Alessandra Villarà on 11/01/2023.
// matricola 1137125

#include "Game_Master.h"
#include "writeLog.h"


Game_Master::Game_Master(bool game_mode, int max) {
    max_Turns=max;
    if(game_mode) {
        Player1= new Com_Player("P1");  //in questo modo si carica automaticamente il costruttore per ogni nave del gioco
        Player2=new Com_Player("P2");
    }
    else {
        Player1=new Human_Player("P1");
        Player2=new Com_Player("P2");
    }
}
Game_Master::Game_Master(std::vector<std::string> coord_P1, std::vector<std::string> coord_P2) {
    Player1=new Com_Player(coord_P1);
    Player2=new Com_Player(coord_P2);
}

//method uses to actually play
//false until you reach the maximum number of turns, or one of the player loses all ships
bool Game_Master::Execute_Turn() {
    std::cout<<"*Turno n."<<current_Turn<<std::endl;
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
        current_Turn_Player->check_For_Healing(second);
    if(i==2)
        exploring_Protocol(second);

    current_Turn++;
    return current_Turn>=max_Turns || Player2->check_For_Endgame() || Player1->check_For_Endgame();
}

//method that says who wins the game
void Game_Master::who_Wins() {
    if(current_Turn==max_Turns)
        std::cout<<"*Sono stati giocati "<<max_Turns<<", la partita è finita in parità"<<std::endl;
    else if(Player1->check_For_Endgame())
        std::cout<<"*Ha vinto il giocatore 2!!!"<<std::endl;
    else if(Player2->check_For_Endgame())
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
    std::cout<<"Tocca al player "<<current_Turn_Player->get_Name()<<std::endl;
    moves=current_Turn_Player->get_Coordinates_to_Move();
    writeLog(current_Turn_Player->get_Name() +" "+moves);
    std::cout<<current_Turn_Player->get_Name()<<"   "<<moves<<std::endl;
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
    for (int i =coordinates.get_Y() -2; i <coordinates.get_Y()+ 3; i++) {
        if (i < 0)
            i=0;
        else if (i > 12)
            break;
        else {
            for (int j =coordinates.get_X()-2; j <coordinates.get_X()+3; j++) {
                if (j < 0)
                    j=0;
                else if (j> 12)
                    break;
                else {
                    if (opponent->search_in_Def_Board(Coordinates(j, i)) !=' ')
                        current_Turn_Player->write_in_Atk_Board(Coordinates(j, i), 'Y');
                }
            }
        }
    }
}

void Game_Master::Execute_Turn_Replay(std::string mossa) {
    if(current_Turn%2==0){
        current_Turn_Player=Player2;
        opponent=Player1;
    }
    else {
        current_Turn_Player = Player1;
        opponent = Player2;
    }
    bool correct=ask_For_Coordinates_Replay(mossa);
    if(correct==0)
        return;
    else {
        Coordinates first= Coordinates(moves.substr(0, moves.find_first_of(' ')));
        Coordinates second= Coordinates(moves.substr(moves.find_first_of(' '), moves.length()));
        int i=current_Turn_Player->play(first, second);
        if(i==0)
            fire_Protocol(second);
        if(i==1)
            current_Turn_Player->check_For_Healing(second);
        if(i==2)
            exploring_Protocol(second);

        current_Turn++;

    }

}

bool Game_Master::ask_For_Coordinates_Replay(std::string mossa) {
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