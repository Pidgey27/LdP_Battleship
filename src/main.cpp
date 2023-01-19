//
// Created by Damiano Marconato
//  matr 1221875
//

#include <iostream>
#include "Battle_Ship.h"
#include "Support_Ship.h"
#include "writeLog.h"

int main(int argc, char const *argv[])
{
int max_mosse;
    std::cout << argv[1];
    std::string type_of_game = argv[1];

    while(type_of_game != "PC" && type_of_game != "CC" && type_of_game != "V"){
        std::cout << "Riesegui utilizzando un compando valido tra" << std::endl << 
                " PC - Player VS Computer " << std::endl <<
                " CC -  Computer VS Computer " << std::endl <<
                " V - Start replay " << std::endl;
                std::cout << "-> ";
                std::cin >> type_of_game;
    }
    //Prova stampa dato di log 
    writeLog wl(type_of_game);
        if(type_of_game == "PC"){
            std::cout << "Player VS Computer" << std::endl;
            Coordinates prua("H9");
            Coordinates poppa("F9");
            Support_Ship sp(poppa,prua, true);
            
            // Prova di stampa 
            writeLog wl(std::string(1,sp.get_Name()), prua.to_String(),poppa.to_String());

        }else if (type_of_game == "CC"){
            std::cout <<
            "Quante mosse possono effettuate i due computer prima di terminare la parita?" << std::endl;
            std::cin >> max_mosse;

        }else if (type_of_game == "V")
            std::cout << "Start replay";

    return 0;
}









