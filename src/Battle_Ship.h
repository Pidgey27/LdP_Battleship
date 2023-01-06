//
// Created by Damiano 
//


#include "Ship.h"
#include "Coordinates.h"


class Battle_Ship : protected Ship{   


    public:
        
        Battle_Ship(Coordinates first, Coordinates last);
        void action(Coordinates first, Coordinates last);
        void setDirection(Coordinates first, Coordinates last);
        void setCenter_X(Coordinates first, Coordinates last);
        void setCenter_Y(Coordinates first, Coordinates last);


        bool checkBattleShip(Coordinates first, Coordinates last);
        bool getDirection();
        int getCenter_X();
        int getCenter_Y();
};