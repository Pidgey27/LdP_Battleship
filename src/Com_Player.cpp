//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125
#include "Com_Player.h"
#include "Player.h"
#include "Ship.h"
#include <chrono>
#include <ctime>

Coordinates Com_Player::Randomly_get_Ship() {
    unsigned seed1;
    seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    int n=rand() % pieces.size();
    return {pieces[n]->get_Center_X(), pieces[n]->get_Center_Y()};
}

Coordinates Com_Player::get_Real_Random_Coordinates() {
    unsigned seed1;
    seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    int x=rand()%12;
    int y=rand()%12;
    return {x, y};
}

Coordinates Com_Player::Random_Coordinates_to_Construct_Ship(char name_ship, Coordinates first_coord) {
    unsigned seed1;
    seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    bool direction=rand()%2;
    bool plus_or_minus=rand()%2;
    int dim;
    int x, y;
    if(name_ship=='S')
        dim=2;
    if(name_ship=='B')
        dim=4;
    if (direction && (first_coord.get_X() + dim) < 12) {
        x = first_coord.get_X() + dim;
        y = first_coord.get_Y();
    }
    if (direction && (first_coord.get_X() - dim) > 0) {
        x = first_coord.get_X() - dim;
        y = first_coord.get_Y();
    }
    if (!direction && (first_coord.get_Y() + dim) < 12) {
        x = first_coord.get_X();
        y = first_coord.get_Y() + dim;
    }
    if (!direction && (first_coord.get_Y() - dim) > 0) {
        x = first_coord.get_X();
        y = first_coord.get_Y() - dim;
    }
    return Coordinates(x,y);
}

Com_Player::Com_Player() {
    for(int i=0; i<3;) {
        while (!declare_Battleship());
        i++;
    }
    for(int i=0; i<4; i++) {
        while (!declare_SupportShip());
        i++;
    }
    while(!declare_Submarine());
    while(!declare_Submarine());
    std::cout<<"Elementi scacchiera creati"<<std::endl;
}

bool Com_Player::declare_Submarine() {
    Coordinates monocoord=get_Real_Random_Coordinates();
    std::cout<<"Provo a dichiare un submarine con coordinate "<<monocoord<<std::endl;
    try {
        board->addSubmarine(monocoord);
    }catch(std::invalid_argument &e) {
        std::cout<<"Failure"<<std::endl;
        return false;
    }
    pieces.emplace_back(new Submarine(monocoord));
    std::cout<<"Success!"<<std::endl;
    return true;
}

bool Com_Player::declare_SupportShip() {
    Coordinates first=get_Real_Random_Coordinates();
    Coordinates second = Random_Coordinates_to_Construct_Ship('S', first);
    std::cout<<"Provo a costruire una support ship con coordinate"<<first<<" "<<second<<std::endl;
    try {
        board->addSupportShip(first, second);
}catch (std::invalid_argument &e) {
        std::cout<<"Failure"<<std::endl;
        return false;
    }
    pieces.emplace_back(new Support_Ship(first, second));
    std::cout<<"Success!"<<std::endl;
    return true;
}

bool Com_Player::declare_Battleship() {
    Coordinates first=get_Real_Random_Coordinates();
    Coordinates second=Random_Coordinates_to_Construct_Ship('B', first);
    std::cout<<"Provo a dichiarare una battleship con coordinate "<<first<<" "<<second<<std::endl;
    try {
        board->addBattleShip(first, second);
    }catch (std::invalid_argument &e) {
        std::cout<<"Failure"<<std::endl;
        return false;
    }
        pieces.emplace_back(new Battle_Ship(first, second));
    std::cout<<"Success!"<<std::endl;
    return true;
}

std::string Com_Player::get_Coordinates_to_Move() {
    //da implementare controllo su board!!
    return Randomly_get_Ship().to_String() + " " + get_Real_Random_Coordinates().to_String();
}

Com_Player::~Com_Player() {
    pieces.clear();
    delete board;
}





