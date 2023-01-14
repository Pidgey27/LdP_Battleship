//
// Created by Damiano 
//


#include "Support_Ship.h"
#include <iostream>

Support_Ship::Support_Ship(Coordinates first, Coordinates last) : Ship(first,last){

     if(checkSupportShip(first,last)){
        setDirection(first,last);
        setCenter_X(first,last);
        setCenter_Y(first,last);
        setName('S');
     }
     else
        throw std::invalid_argument("- Error Coordinates -");

}

 void Support_Ship::action(Coordinates first, Coordinates last){
    std::cout << "move to " << last.get_X() << last.get_Y();
 }

 void Support_Ship::setDirection(Coordinates first, Coordinates last){
    if(first.get_X() == last.get_X())
        //Orizzontale 
         orientation = 0;
    else 
        //Verticale
         orientation = 1;

 }

 void Support_Ship::reset_Armor(bool reset){
        memset(armour, 0, dimension);
}

void Support_Ship::setName(char n) { 
        name = n;
}
 
 bool Support_Ship::getDirection(){ return orientation; }

//Essendo la barca lung a 5 il centro è sempre l'ultimo valore -2 nel caco sia in verticale 
 void Support_Ship::setCenter_X(Coordinates first, Coordinates last){
    if(first.get_X() != last.get_X())
        center_X = last.get_X() - 1;
    else 
        center_X = last.get_X();

 }

  void Support_Ship::setCenter_Y(Coordinates first, Coordinates last){
    if(first.get_Y() != last.get_Y())
        center_Y = last.get_Y() - 1;
    else 
        center_Y = last.get_Y();

 }

 int Support_Ship::getCenter_X(){    return center_X; }
 int Support_Ship::getCenter_Y(){    return center_Y; }

//Check coordinates
 bool Support_Ship::checkSupportShip(Coordinates first, Coordinates last){
    
    if((first.get_X() == last.get_X()) && ((last.get_Y() - first.get_Y()) == 2)){
        return true;
    }else if ((first.get_Y() == last.get_Y()) && ((last.get_X() - first.get_X()) == 2)){
        return true;
    }
    return false;
 }

 char Support_Ship::get_Name(){ 
    return name;
}

int Support_Ship::get_Dimension(){
    return dimension;
}

 