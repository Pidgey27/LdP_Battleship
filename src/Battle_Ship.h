//
// Created by Damiano 
//


#include "Ship.h"
#include "Coordinates.h"


class Battle_Ship : public Ship{   

    protected:
        const int dimension = 5;
        bool *armour = new bool[dimension];
   

    public:
        
        Battle_Ship(Coordinates first, Coordinates last);
        ~Battle_Ship(){ delete armour;};
        void action(Coordinates first, Coordinates last);
        void setDirection(Coordinates first, Coordinates last);
        void setCenter_X(Coordinates first, Coordinates last);
        void setCenter_Y(Coordinates first, Coordinates last);
        void setName(char n);
        void reset_Armor(bool reset);
        void set_Injured(int n);


        bool checkBattleShip(Coordinates first, Coordinates last);
        bool getDirection();
        int getCenter_X();
        int getCenter_Y();
        char get_Name();
        int get_Dimension();
        bool isDead();
};