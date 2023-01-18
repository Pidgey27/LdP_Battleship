//
// Created by Damiano Marconato
//  matr 1221875
//


#include "Ship.h"
#include "Coordinates.h"



class Support_Ship : public Ship{   
    protected:
        const int dimension = 3;
        bool *armour = new bool[dimension];
        char name='S';          //letter to identify the ship (S for support_ship, E for Submarine, C for Battle_ship)
        bool orientation;   //1 for horizontal, 0 for vertical

public:
        
        Support_Ship(Coordinates first, Coordinates last, bool boh);

        ~Support_Ship() override;

        void action(Coordinates first, Coordinates last) override;
        void setDirection(Coordinates first, Coordinates last);
        void setCenter_X(Coordinates first, Coordinates last);
        void setCenter_Y(Coordinates first, Coordinates last);
        void setCenter(Coordinates last);
        void setName(char n);
        void reset_Armor(bool reset);
        void set_Injured(int n);
        bool where_Hit(int n);
        bool checkSupportShip(Coordinates first, Coordinates last);
        bool getDirection();
        int getCenter_X();
        int getCenter_Y();
        char get_Name();
        int get_Dimension();
        bool isDead();
};