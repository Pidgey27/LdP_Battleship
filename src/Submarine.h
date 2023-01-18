//
// Created by Damiano 
//

#include "Ship.h"
#include "Coordinates.h"


class Submarine : public Ship{   

    protected:
        const int dimension = 1;
        bool *armour = new bool[dimension];
        char name='E';          //letter to identify the ship (S for support_ship, E for Submarine, C for Battle_ship)



public:
        Submarine(Submarine &&)=delete;
        Submarine(Submarine const&)=delete;
        Submarine operator= (Submarine const&)=delete;
        Submarine(Coordinates mono_Coord);
        ~Submarine(){};
        void action(Coordinates first, Coordinates last) override;
        void setCenter(Coordinates mono_Cord);
        void setName(char n);
        void reset_Armor(bool reset);
        void set_Injured(int n);
        int get_Center_X();
        int get_Center_Y();
        char get_Name();
        int get_Dimension();
        bool isDead();
};