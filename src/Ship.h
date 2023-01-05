//
// Created by Aless on 21/12/2022.
//

#ifndef LDP_BATTLESHIP_SHIP_H
#define LDP_BATTLESHIP_SHIP_H
#include "Coordinates.h"

class Ship {

public:
    Ship(Coordinates first, Coordinates last){};   //to implement on Battle_Ship and Suppport_Ship
    Ship(Coordinates mono_Coord){}; //to implement on Submarine
    // Aggiungendo = 0 blocco la possibilotà di istanziare oggetti con i seguenti metodi e nel caso 
    // Decidessi di estendere la classe ho l'obbligo di implementare i metodi.
    // Nel caso non li implementassi il compilatore di lancia un errore in fase di compilazione 
    virtual void action(Coordinates first, Coordinates last);
    void reset_Armor(bool reset); 
};

#endif //LDP_BATTLESHIP_SHIP_H
