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
            center_X = mono_Coord.get_X();
        }

        void Submarine::reset_Armor(bool reset){
            memset(armour, 0, dimension);
        }

        void Submarine::setName(char n) { 
            name = n;
        }
        
        bool Submarine::getDirection(){
            return orientation;
        }

        int Submarine::getCenter(){
            return center_X;
        }

        char Submarine::get_Name(){ 
            return name;
        }

        int Submarine::get_Dimension(){
            return dimension;
        }