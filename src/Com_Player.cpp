//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125
#include "Com_Player.h"
#include "Player.h"
#include <chrono>
#include "Coordinates.h"

//randomly selects a ship from pieces vector, to ensure first coordinate as always correct
 void Com_Player::Randomly_get_Ship() {
    unsigned seed1;
    seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    int n=rand() % ships;
    temp1={pieces[n]->get_Center_X(), pieces[n]->get_Center_Y()};
}

//creates real random coordinates
void Com_Player::get_Real_Random_Coordinates() {
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    int x=rand()%12;
    int y=rand()%12;
    temp1={x, y};
}

//creates correct random coordinates to construct a ship, based on its type, distinguished by name_ship
void Com_Player::Random_Coordinates_to_Construct_Ship(char name_ship, Coordinates first_coord) {
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    bool direction=rand()%2;
    int dim;
    if(name_ship=='S')
        dim=2;
    if(name_ship=='B')
        dim=4;
    if (direction && (first_coord.get_X() + dim) < 12)
        temp2={first_coord.get_X() + dim, first_coord.get_Y()};
    else if (direction && (first_coord.get_X() - dim) > 0)
        temp2={first_coord.get_X() - dim, first_coord.get_Y()};
    else if (!direction && (first_coord.get_Y() + dim) < 12)
        temp2={first_coord.get_X(), first_coord.get_Y() + dim};
    else if (!direction && (first_coord.get_Y() - dim) > 0)
        temp2={first_coord.get_X(), first_coord.get_Y() - dim};
    else throw std::invalid_argument("Eccezione in Random Construct ship");
}

Com_Player::Com_Player() {
    for(int i=0; i<3; i++) {
        while (!declare_Battleship());
    }
    for(int i=0; i<3; i++) {
        while (!declare_SupportShip());
    }
    while(!declare_Submarine());
    while(!declare_Submarine());
    std::cout<<"*Elementi scacchiera creati"<<std::endl;
}

//method used to declare a submarine; checks if the coordinates are empty on the board. If everything is ok returns true.
bool Com_Player::declare_Submarine() {
    get_Real_Random_Coordinates();
    try {
        board->addSubmarine(temp1);
        pieces.emplace_back(new Submarine(temp1));
        return true;
    }catch(std::invalid_argument &e) {
        return false;
    }
}

//method used to declare a support ship; checks if the coordinates used by the ship are empty in the board. If everything is
//ok returns true.
bool Com_Player::declare_SupportShip() {
    get_Real_Random_Coordinates();
    try {
        Random_Coordinates_to_Construct_Ship('S', temp1);
        order_Coord();
        try {
            board->addSupportShip(temp1, temp2);
            pieces.emplace_back(new Support_Ship(temp1, temp2));
            return true;
        } catch (std::invalid_argument &e) {
            return false;
        }
    } catch (std::invalid_argument &e) {
        std::cout << "Eccezione in Random Construct ship" << std::endl;
        return false;
    }
}

//method used to declare a battleship; checks if the coordinates used by the ship are empty in the board. If everything is
//ok returns true.
bool Com_Player::declare_Battleship() {
    get_Real_Random_Coordinates();
    try{
        Random_Coordinates_to_Construct_Ship('B', temp1);
        order_Coord();
        try {
            board->addBattleShip(temp1, temp2);
            pieces.emplace_back(new Battle_Ship(temp1, temp2));
            return true;
        }catch (std::invalid_argument &e) {
            return false;
        }
    }
    catch (std::invalid_argument &e) {
        std::cout << "Eccezione in Random Construct ship" << std::endl;
        return false;
    }
}

//method that returns correct random coordinates for a move. Used in architecture's upper level as standard turn move
std::string Com_Player::get_Coordinates_to_Move() {
    Randomly_get_Ship();
    Coordinates temporary=temp1;
    std::cout<<temp1<<std::endl;
    get_Real_Random_Coordinates();
    if(board->get(temporary)!='B' && board->get(temporary)!='b') {
        while(board->get(temp2)!=' ') {
            get_Real_Random_Coordinates();
        }
    }
    return temporary.to_String() + " " + temp1.to_String();
}

//method that orders coordinates, to distinguish bow and tail. used only in constructors
void Com_Player::order_Coord() {
    Coordinates realTemp;
    if(temp1.get_X()==temp2.get_X())
        if(temp2.get_Y()<temp1.get_Y()) {
            realTemp=temp2;
            temp2=temp1;
            temp1=realTemp;
        }
    if(temp1.get_Y()==temp2.get_Y())
        if(temp2.get_X()<temp1.get_X()) {
            realTemp=temp2;
            temp2=temp1;
            temp1=realTemp;
        }
}

Com_Player::~Com_Player() {
    pieces.clear();
}


