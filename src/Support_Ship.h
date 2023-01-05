//
// Created by Damiano 
//


#include "Ship.h"
#include "Coordinates.h"


class Support_Ship : protected Ship{   

    protected:
        int center_X;
        int center_Y;
        char name;
        bool orientation; //0 for horizontal, 1 vertical
        bool armor[5];   //the dimension of armor depends on the type of ship
        

    public:
        
        Support_Ship(Coordinates first, Coordinates last);
        void action(Coordinates first, Coordinates last);
        void setDirection(Coordinates first, Coordinates last);
        void setCenter_X(Coordinates first, Coordinates last);
        void setCenter_Y(Coordinates first, Coordinates last);


        bool checkSupportShip(Coordinates first, Coordinates last);
        bool getDirection();
        int getCenter_X();
        int getCenter_Y();
};