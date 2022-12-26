//
// Created by Aless on 22/12/2022.
//
#include "C:\Users\Aless\Documents\GitHub\LdP_Battleship\src\Coordinates.h"
void test_char_coordinates_conversion() {
    char test_board[12][12] {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                             };
    Coordinates uno("b10");
    Coordinates due("a3");
    test_board[uno.get_Y()][uno.get_X()]='x';
    test_board[due.get_Y()][due.get_X()]='x';
    std::cout<<"Input "<<uno.to_String()<<" "<<due.to_String()<<std::endl;      //check on method to_String: ok
    int i=0;
    int j=0;
    for(i=0; i<=11; i++ ) {
        for(j=0; j<=11; j++) {
            std::cout<<test_board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
    void test_coordinates_basic_conversion() {       //test ok
        std::string uno = "A2";
        std::string due = "a2";
        std::string invalid1 = "%7";
        std::string invalid2 = "oooooo";
        std::string with_spaces = " b 2";
        std::string invalid3 = "p132";
        std::string invalid4 = "p-2";
        Coordinates a(uno);
        Coordinates b(due);
        //Coordinates c(invalid1);    // riconosce i caratteri invalidi, lancia eccezione
        //Coordinates d(invalid2);      //riconosce le stringhe troppo lunghe, lancia eccezione
        Coordinates e(with_spaces); //riconosce ed elimina gli spazi
        //Coordinates f(invalid3);      //riconosce le coordinate fuori dalla scacchiera e lancia eccezione
        Coordinates g(invalid3);    //idem
        std::cout << "prova conversione " << uno << " " << a.get_Y() << " " << a.get_X() << std::endl;
        std::cout << "prova conversione " << due << " " << b.get_Y() << " " << b.get_X() << std::endl;
        std::cout << "prova conversione " << invalid3 << " " << g.get_Y() << " " << g.get_X() << std::endl;
    }

    void test_input_from_keyboard() {
        char test_board[13][13] {'A', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'B', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'C', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'D', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'E', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'F', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'G', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'H', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'I', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'J', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'K', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 'L', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o','o','o','o',
                                 ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', static_cast<char>('10'), static_cast<char>('11'), static_cast<char>('12') };
        int i=0;
        int j=0;
        for(i=0; i<=12; i++ ) {
            for(j=0; j<=12; j++) {
                std::cout<<test_board[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<"Inserisci delle coordinate sotto forma A1"<<std::endl;
        std::string coordinates;
        std::cin>>coordinates;
        Coordinates a(coordinates);
        test_board[a.get_Y()][a.get_X()]='x';
        std::cout<<"ho inserito "<<coordinates<<std::endl;
        for(i=0; i<=12; i++ ) {
            for(j=0; j<=12; j++) {
                std::cout<<test_board[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        }

int main () {
    //test_coordinates_basic_conversion();
    //test_char_coordinates_conversion();
    test_input_from_keyboard();
    return 0;
}