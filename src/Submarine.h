//
// Created by Damiano 
//

#include "Ship.h"
#include "Coordinates.h"


class Submarine : protected Ship{   

    protected:
        int center;
        char name;
        bool orientation; //0 for horizontal, 1 vertical
        bool armor[5];   //the dimension of armor depends on the type of ship
        

    public:
        
        Submarine(Coordinates mono_Coord);
        void action(Coordinates first, Coordinates last);
        void setCenter(Coordinates mono_Cord);
        
        bool getDirection();
        int getCenter();
};