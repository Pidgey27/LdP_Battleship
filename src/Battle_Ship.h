//
// Created by Damiano 
//


#include "Ship.h"
#include "Coordinates.h"


class Battle_Ship : public Ship{   

    protected:
        int dimension = 5;
         bool *armour = new bool[dimension];
   

    public:
        
        Battle_Ship(Coordinates first, Coordinates last);
        void action(Coordinates first, Coordinates last);
        void setDirection(Coordinates first, Coordinates last);
        void setCenter_X(Coordinates first, Coordinates last);
        void setCenter_Y(Coordinates first, Coordinates last);
        void setName(char n);
        void reset_Armor(bool reset);


        bool checkBattleShip(Coordinates first, Coordinates last);
        bool getDirection();
        int getCenter_X();
        int getCenter_Y();
        char get_Name();
        int get_Dimension();
};