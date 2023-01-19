//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125
#include "Com_Player.h"
#include "Player.h"
#include <chrono>
#include "Coordinates.h"
#include "writeLog.h"

Com_Player::Com_Player(std::string nome) {
    name=nome;
    int i;
    for(i=0; i<3; i++)
        while(!declare_Battleship());
    for(i=0; i<3; i++)
        while(!declare_SupportShip());
    for(i=0; i<2; i++)
        while(!declare_Submarine());
    std::cout<<"*Elementi scacchiera creati"<<std::endl;
}

//new constructor for replay games
Com_Player::Com_Player(std::vector<std::string> coordinates_for_constructor) {
    for(int i=0; i<3; i++){
    Coordinates prua(coordinates_for_constructor.at(i).substr(0, coordinates_for_constructor.at(i).find_first_of(' ')));
    Coordinates poppa(coordinates_for_constructor.at(i).substr(coordinates_for_constructor.at(i).find_first_of(' '), coordinates_for_constructor.at(i).length()));
    Battle_Ship battle(prua, poppa);
    battleship.push_back(std::move(battle));
    }
    for(int i=3; i<6; i++){
        Coordinates prua(coordinates_for_constructor.at(i).substr(0, coordinates_for_constructor.at(i).find_first_of(' ')));
        Coordinates poppa(coordinates_for_constructor.at(i).substr(coordinates_for_constructor.at(i).find_first_of(' '), coordinates_for_constructor.at(i).length()));
        Support_Ship supp(prua, poppa, true);
        support.push_back(std::move(supp));
    }
    for(int i=6; i<8; i++){
        Coordinates monocoord(coordinates_for_constructor.at(i));
        Submarine sub(monocoord);
        submarine.push_back(std::move(sub));
    }
}

//method used to declare a submarine; checks if the coordinates are empty on the board. If everything is ok returns true.
bool Com_Player::declare_Submarine() {
    get_Random_Coordinates();
    try {
        Submarine sub1(temp1);
        board.addSubmarine(temp1);
        submarine.push_back(std::move(sub1));
        writeLog(name +" "+temp1.to_String());
        return true;
    }catch(std::invalid_argument &e) {
        return false;
    }
}

//method used to declare a support ship; checks if the coordinates used by the ship are empty in the board. If everything is
//ok returns true.
bool Com_Player::declare_SupportShip() {
    get_Random_Coordinates();
    try {
        Random_Coordinates_to_Construct_Ship('S', temp1);
        order_Coord();
        try {
            Support_Ship supp(temp1, temp2, true);
            board.addSupportShip(temp1, temp2);
            support.push_back(std::move(supp));
            writeLog(name+" "+temp1.to_String()+" "+temp2.to_String());
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
    get_Random_Coordinates();
    try{
        Random_Coordinates_to_Construct_Ship('C', temp1);
        order_Coord();
        try {
            Battle_Ship battle(temp1, temp2);
            board.addBattleShip(temp1, temp2);
            battleship.push_back(std::move(battle));
            writeLog(name+" "+temp1.to_String()+" "+temp2.to_String());
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


//randomly selects a ship from pieces vector, to ensure first coordinate as always correct
int Com_Player::Randomly_get_Ship() {
    unsigned seed1;
    seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    int which_v=rand()%3;
    if(which_v==0) {
        int n = rand() % battleship.size();
        temp1={battleship.at(n).get_Center_X(), battleship.at(n).get_Center_Y()};
        return n;
    }
    else if(which_v==1){
        int n = rand() % support.size();
        temp1={support.at(n).get_Center_X(), support.at(n).get_Center_Y()};
        return n;
    }
    else if(which_v==2){
        int n = rand() % submarine.size();
        temp1={submarine.at(n).get_Center_X(), submarine.at(n).get_Center_Y()};
        return n;
    }
}

//creates real random coordinates
void Com_Player::get_Random_Coordinates_to_Move(int i, char name) {
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    int n, m, x, y;
    if(name=='S') {
        if(support.at(i).getDirection()==0) {
            n = 1;
            m=0;
        }
        else{
            n=0;
            m=1;
        }
        bool condition;
        do {
            x = rand() % 12;
            y = rand() % 12;
            condition=true;
            if(x+ m>12|| y+n>12 || x-m<0 || y-n<0)
                condition= false;
            if(board.get(Coordinates(x+ m, y+n))!=' ' && board.get(Coordinates(x-m, y-n))!=' ')
                condition= false;
        } while (!condition);
        temp1={x, y};
    }
    else if(name=='C') {
        x = rand() % 12;
        y = rand() % 12;
        temp1={x, y};
    }
    else {
        do{
            x = rand() % 12;
            y = rand() % 12;
        }while(board.get(Coordinates(x, y))!=' ');
        temp1={x, y};
    }
}

void Com_Player::get_Random_Coordinates() {
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed1);
    int x = rand() % 12;
    int y = rand() % 12;
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
    if(name_ship=='C')
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


//method that returns correct random coordinates for a move. Used in architecture's upper level as standard turn move
std::string Com_Player::get_Coordinates_to_Move() {
    int i = Randomly_get_Ship();
    Coordinates temporary = temp1;
    get_Random_Coordinates_to_Move(i, board.get(temporary));
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


