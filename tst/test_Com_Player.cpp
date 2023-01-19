//
// Created by Alessandra Villarà on 10/01/2023.
// matricola 1137125
#include "src/Com_Player.h"
static void test_Dummy_Constructor_And_Search() {
    Com_Player computer("com");
    std::cout<<"Ho inserito queste navi di default"<<std::endl;
    computer.show_Pieces();
    std::cout<<"Cerco una nave in A8"<<std::endl;
    int i=computer.search_For_Ship(Coordinates("A8")); //trova anche con name in minuscolo
    if (i==0)
        std::cout<<"Test centro riuscito!!!"<<std::endl;
    i=computer.search_For_Ship(Coordinates("C5"));
    if(i==1)
        std::cout<<"Test ricerca fuori dal centro riuscito!!!"<<std::endl;
}
static void test_Random_Get_Coordinates_to_Move() {
    Com_Player computer("com");
    std::string prova=computer.get_Coordinates_to_Move();
    std::cout<<"Mossa casuale uscita: "<<prova<<std::endl;
}
 /* Dummy Constructor for com_Player
  * Com_Player::Com_Player() {
    Coordinates prua("A6");
    Coordinates poppa("A10");
    pieces.emplace_back(new Battle_Ship(prua, poppa));
    pieces.emplace_back(new Battle_Ship(Coordinates("C1"), Coordinates("C5")));
    pieces.emplace_back(new Submarine(Coordinates("D5")));
}
  */

 static void test_Real_Constructor() {
     std::cout<<"Ho inserito queste navi di casuali"<<std::endl;
     Com_Player computer("com");
 }

 //test riuscito, ritorna 0 per verticale, 1 per orizzontale.
 static void test_orientation() {
    Com_Player computer("com");
    computer.show_Pieces();
    computer.print_Def_Board();
    computer.show_Ship(2, 'S');
    std::cout<<"orientamento del pezzo uguale a "<<computer.get_Orientation(2, 'S');
 }

