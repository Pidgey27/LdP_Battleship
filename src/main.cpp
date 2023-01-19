//
// Created by Damiano Marconato
//  matr 1221875
//

#include <iostream>
//#include "Replay.h"
#include "Game_Master.h"
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

        if(type_of_game == "PC"){
            Game_Master gmPC(false);
            while(gmPC.Execute_Turn());
            gmPC.who_Wins();

        }else if (type_of_game == "CC"){
            std::cout <<
            "Quante mosse possono effettuate i due computer prima di terminare la parita?" << std::endl;
            std::cin >> max_mosse;
            Game_Master gmCC(max_mosse,true);
            while(gmCC.Execute_Turn());
            gmCC.who_Wins();
            
        }else if (type_of_game == "V")
      //      Replay r;

        

    return 0;
}









