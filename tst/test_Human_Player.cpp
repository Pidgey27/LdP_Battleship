/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/
#include "src/Human_Player.h"


static void test_Human_Player() {
 
    Human_Player player("P1");
    player.show_Pieces();
    for(int i = 0; i < 10; i++){
        std::string prova = player.get_Coordinates_to_Move();
        std::cout << "Coordinate correttamente inserite: " << prova << std::endl;
    }

}

