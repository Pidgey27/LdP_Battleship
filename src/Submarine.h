//
// Created by Damiano 
//

#include "Ship.h"
#include "Coordinates.h"


class Submarine : protected Ship{   
        

    public:
        
        Submarine(Coordinates mono_Coord);
        void action(Coordinates first, Coordinates last);
        void setCenter(Coordinates mono_Cord);
        
        bool getDirection();
        int getCenter();
};