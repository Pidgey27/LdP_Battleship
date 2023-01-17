
#include "src/Human_Player.h"



static void test_Get_Coordinates_to_Move() {
 
    Human_Player player;
    while(true){
        std::string prova = player.get_Coordinates_to_Move();
        std::cout << prova;
    }
}

