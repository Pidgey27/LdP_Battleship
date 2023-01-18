    //
// Created by Damiano 
//


#include "Battle_Ship.h"
#include <iostream>
#include <stdlib.h> 

Battle_Ship::Battle_Ship(Coordinates first, Coordinates last){

     if(checkBattleShip(first,last)){
        setDirection(first,last);
        setCenter_X(first,last);
        setCenter_Y(first,last);
        setName('C');
         reset_Armor(true);
     }
     else
        throw std::invalid_argument("- Error Coordinates Battle_Ship -");

}

 void Battle_Ship::action(Coordinates first, Coordinates last){
    std::cout << "*Fuoco su " << last <<std::endl;
 }

 void Battle_Ship::setDirection(Coordinates first, Coordinates last){
    if(first.get_X() == last.get_X())
        //Verticale
         orientation = 0;
    else 
        //Orizzontale
         orientation = 1;

 }
 
 bool Battle_Ship::getDirection(){ return orientation; }

//Essendo la barca lung a 5 il centro è sempre l'ultimo valore -2 nel caco sia in verticale 
 void Battle_Ship::setCenter_X(Coordinates first, Coordinates last){
    if(first.get_X() != last.get_X()){
        if(first.get_X() < last.get_X())
             center_X = last.get_X() - 2;
        else center_X = first.get_X() - 2;
    }else 
        center_X = last.get_X();

 }

  void Battle_Ship::setCenter_Y(Coordinates first, Coordinates last){
    if(first.get_Y() != last.get_Y()){
        if(first.get_Y() < last.get_Y())
            center_Y = last.get_Y() - 2;
        else center_Y = first.get_Y() - 2;
    }else 
        center_Y = last.get_Y();

 }

 void Battle_Ship::reset_Armor(bool reset){
    memset(armour, 0, dimension);
 }

  void Battle_Ship::setName(char n) { 
    name = n;
}

void  Battle_Ship::set_Injured(int n){
       if(armour[n] == 1)
             std::cout << " You've already hit!!! ";
        else armour[n] = 1; 
 }

 int Battle_Ship::getCenter_X(){    return center_X; }
 int Battle_Ship::getCenter_Y(){    return center_Y; }

//Check coordinates
 bool Battle_Ship::checkBattleShip(Coordinates first, Coordinates last){
    
    if((first.get_X() == last.get_X()) && (abs(last.get_Y() - first.get_Y()) == 4)){
        return true;
    }else if ((first.get_Y() == last.get_Y()) && (abs(last.get_X() - first.get_X()) == 4)){
        return true;
    }
    return false;
 }

char Battle_Ship::get_Name(){ 
    return 'C';
}

int Battle_Ship::get_Dimension(){
    return dimension;
}

bool Battle_Ship::isDead(){
    for(int i=0 ; i<dimension ; i++){
        if(armour[i] == 0){
            return false;
        }
    }
    return true;
}
 