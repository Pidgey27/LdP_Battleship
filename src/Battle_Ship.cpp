    //
// Created by Damiano 
//


#include "Battle_Ship.h"
#include <iostream>

Battle_Ship::Battle_Ship(Coordinates first, Coordinates last) : Ship(first,last){

     if(checkBattleShip(first,last)){
        setDirection(first,last);
        setCenter_X(first,last);
        setCenter_Y(first,last);
     }
     else
        std::cout << "Coordinate non valide";

}

 void Battle_Ship::action(Coordinates first, Coordinates last){
    
 }

 void Battle_Ship::setDirection(Coordinates first, Coordinates last){
    if(first.get_X() == last.get_X())
        //Orizzontale 
         orientation = 0;
    else 
        //Verticale
         orientation = 1;

 }
 
 bool Battle_Ship::getDirection(){ return orientation; }

//Essendo la barca lung a 5 il centro è sempre l'ultimo valore -2 nel caco sia in verticale 
 void Battle_Ship::setCenter_X(Coordinates first, Coordinates last){
    if(first.get_X() != last.get_X())
        center_X = last.get_X() - 2;
    else 
        center_X = last.get_X();

 }

  void Battle_Ship::setCenter_Y(Coordinates first, Coordinates last){
    if(first.get_Y() != last.get_Y())
        center_Y = last.get_Y() - 2;
    else 
        center_Y = last.get_Y();

 }

 int Battle_Ship::getCenter_X(){    return center_X; }
 int Battle_Ship::getCenter_Y(){    return center_Y; }

//Check coordinates
 bool Battle_Ship::checkBattleShip(Coordinates first, Coordinates last){
    
    if((first.get_X() == last.get_X()) && ((last.get_Y() - first.get_Y()) == 4)){
        return true;
    }else if ((first.get_Y() == last.get_Y()) && ((last.get_X() - first.get_X()) == 4)){
        return true;
    }
    return false;
 }

 