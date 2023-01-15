//
// Created by Alessandra Villarà on 15/01/2023.
// matricola 1137125

#include "src/Game_Master.h"

/************************************************
Alcuni di questi test(quelli commentati) funzionano solo se si impostano le variabili comPlayer e Player come PUBLIC, quindi bisogna spostarli su public prima
 e poi decommentare i test.
 Questi test sono nati per testare il memory leak del programma.
************************************************/

static void test_costruttore() {
    Game_Master master(1, 10);
    //il costruttore funziona!
}

/*
//il test rimuove la nave senza causare memory leak, ritorna un return 0 senza alcun problema.
static void test_rimuovi_nave() {
    Game_Master master(1, 10);
    master.Player1->show_Pieces();
    master.Player1->remove_Ship(2);
    master.Player1->show_Pieces();
}

//anche qui ritorna 0, dopo aver rimosso tutti i pezzi di un player
//provo con due
static void test_clear_all() {
    Game_Master master(1, 10);
    master.Player2->show_Pieces();
    for(int i=0; i<8; i++)
        master.Player1->remove_Ship(0);
    master.Player1->show_Pieces();
    for(int i=0; i<8; i++)
        master.Player2->remove_Ship(0);
}

//se inserisci l'input giusto, non trova il pezzo cercato dopo averlo eliminato. anche qui niente memory leak
static void test_search_after_clearing_all() {
    Game_Master master(1, 10);
    master.Player2->show_Pieces();
    for(int i=0; i<8; i++)
        master.Player1->remove_Ship(0);
    master.Player1->show_Pieces();
    for(int i=0; i<8; i++)
        master.Player2->remove_Ship(0);
master.Player2->show_Pieces();
std::cout<<"Inserisco le coordinate per cercare un pezzo che dovrebbe essere stato eliminato"<<std::endl;
std::string j;
std::cin>>j;
int h=master.Player2->search_For_Ship(Coordinates(j), 'E');
} */