        //
        // Created by Damiano 
        //
        
        #include "Submarine.h"
        #include <iostream>

        
        Submarine::Submarine(Coordinates mono_Coord) : Ship(mono_Coord){
            setCenter(mono_Coord);
            setName('E');
            reset_Armor(true);
        }

        void Submarine::action(Coordinates first, Coordinates last){
            std::cout << "move to " << last.get_X() << last.get_Y();
        }

        void Submarine::setCenter(Coordinates mono_Coord){
            center_X = mono_Coord.get_X();
            center_Y = mono_Coord.get_Y();
        }

        void Submarine::reset_Armor(bool reset){
            memset(armour, 0, dimension);
        }

        void Submarine::setName(char n) { 
            name = n;
        }

        void  Submarine::set_Injured(int n){
            if(armour[n] == 1)
                    std::cout << " You've already hit!!! ";
                else armour[n] = 1; 
        }
        
        bool Submarine::getDirection(){
            return orientation;
        }

        int Submarine::get_Center_X(){
            return center_X;
        }

        int Submarine::get_Center_Y(){
            return center_Y;
        }

        char Submarine::get_Name(){ 
            return name;
        }

        int Submarine::get_Dimension(){
            return dimension;
        }

        bool Submarine::isDead(){
            for(int i=0 ; i<dimension ; i++){
                if(armour[i] == 0){
                    return false;
                }
            }
            return true;
        }