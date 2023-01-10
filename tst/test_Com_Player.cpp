//
// Created by Alessandra Villarà on 10/01/2023.
// matricola 1137125
#include "src/Com_Player.h"
static void test_Constructor_And_Search() {
    Com_Player computer;
    std::cout<<"Ho inserito queste navi di default"<<std::endl;
    computer.show_Pieces();
    std::cout<<"Cerco una nave in A8"<<std::endl;
    int i=computer.search_For_Ship(Coordinates("A8"), 's'); //trova anche con name in minuscolo
    if (i==0)
        std::cout<<"Test centro riuscito!!!"<<std::endl;
    std::cout<<i;
    i=computer.search_For_Ship(Coordinates("C5"), 's');
    if(i==1)
        std::cout<<"Test  riuscito!!!"<<std::endl;
    std::cout<<i;
}
static void test_Random_Get_Coordinates_to_Move() {
    Com_Player computer;
    std::string prova=computer.get_Coordinates_to_Move();
    std::cout<<"Mossa casuale uscita: "<<prova<<std::endl;
}
