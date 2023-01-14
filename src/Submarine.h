//
// Created by Damiano 
//

#include "Ship.h"
#include "Coordinates.h"


class Submarine : public Ship{   

    protected:
        const int dimension = 1;
         bool *armour = new bool[dimension];
   


    public:
        
        Submarine(Coordinates mono_Coord);
        void action(Coordinates first, Coordinates last);
        void setCenter(Coordinates mono_Cord);
        void setName(char n);
        void reset_Armor(bool reset);
        void set_Injured(int n);


        bool getDirection();
        int get_Center_X();
        int get_Center_Y();
        char get_Name();
        int get_Dimension();
        bool isDead();
};