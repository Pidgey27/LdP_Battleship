        //
        // Created by Damiano 
        //
        
        #include "Submarine.h"
        #include <iostream>
        
        Submarine::Submarine(Coordinates mono_Coord) : Ship(mono_Coord){
            setCenter(mono_Coord);
        }

        void Submarine::action(Coordinates first, Coordinates last){

        }

        void Submarine::setCenter(Coordinates mono_Coord){
            center = mono_Coord.get_X();
        }
        
        bool Submarine::getDirection(){
            return orientation;
        }

        int Submarine::getCenter(){
            return center;
        }