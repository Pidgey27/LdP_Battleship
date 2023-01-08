/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "Board.h"

Board* Board ::instancePtr = NULL;

    //TODO : constructor have to initialize the board with boat
    Board::Board(){
        for(int i = 0; i < 12; i++){
            for(int j  =0; j < 12; j ++){ 
            this->defenseBoard[i][j] = ' ';
            this->attackBoard[i][j] = ' ';
            }
        }
        //addBattleShip();

    }

void Board::printDefBoard(){

    std::cout << "      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|" << std::endl << std::endl;

    for(int i = 0; i < 12; i ++) { //column loop
        char C = 65 + i;
        if((65+i) == 74 || (65+i) == 75 || (65+i) == 76)
            C = 67 + i;
        std::cout << "  "  << C << "   ";
        for(int j  =0; j < 12; j ++){ //row loop
            std::cout << this->defenseBoard[i][j] << " | ";
        }
        std::cout << std::endl; //new line at end of column
        std::cout <<"     ------------------------------------------------";
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

void Board::printAtkBoard(){

        std::cout << "      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|" << std::endl << std::endl;

    for(int i = 0; i < 12; i ++) { //column loop
        char C = 65 + i;
        if((65+i) == 74 || (65+i) == 75 || (65+i) == 76)
            C = 67 + i;
        std::cout << "  "  << C << "   ";
        for(int j  =0; j < 12; j ++){ //row loop
            std::cout << this->attackBoard[i][j] << " | ";
        }
        std::cout << std::endl; //new line at end of column
        std::cout <<"     ------------------------------------------------";
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

void Board::printBoard(){
    std::cout << "\033[1;36m      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|            1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|\033[0m" << std::endl << std::endl;

    for(int i = 0; i < 12; i ++) { //column loop
        char C = 65 + i;
        if((65+i) == 74 || (65+i) == 75 || (65+i) == 76)
            C = 67 + i;
        std::cout << "  \033[1;36m"  << C << "\033[0m   ";
        for(int j  =0; j < 12; j ++){ //row loop
            std::cout << this->defenseBoard[i][j] << " | ";
        }
        std::cout <<"     ";
        std::cout << "  \033[1;36m"  << C << "\033[0m   ";
        for(int j  =0; j < 12; j ++){ //row loop 2 table
            std::cout << this->attackBoard[i][j] << " | ";
        }

        std::cout << std::endl; //new line at end of column
        std::cout <<"     ------------------------------------------------           ------------------------------------------------";
        std::cout << std::endl;
    
    
    }
    std::cout << std::endl;
};

void Board::addBattleShip(){
        //TODO : try and catch of exception "input wrong"
        std::string input;
        for(int i : {0,1,2}){
            std::cout << "Inserisci Coordinate del centro per la prima corazzata"<<  std::endl;
            std::cin >> input;
            Coordinates coordinates = Coordinates(input);
            //check coordinate
            if(coordinates.get_X() < 2 || coordinates.get_X() > 10)
                throw std::runtime_error("Hai inserito una coordinata non valida!");
            if(coordinates.get_Y() < 2 || coordinates.get_Y() > 10)
                throw std::runtime_error("Hai inserito una coordinata non valida!");

            std::cout << "Inserisci se la vuoi ORIZZONTALE oppure VERTICALE (o/v)? "<<  std::endl;
            std::cin >> input;

            if(input.compare("o")== 0){
                int Y = coordinates.get_Y()-2;
                int X = coordinates.get_X();
                for(int i=0; i < 5; i++)
                    defenseBoard[X][Y+i] = 'C';
            }
            if(input.compare("v")== 0){
                int Y = coordinates.get_Y();
                std::cout << Y;
                int X = coordinates.get_X()-2;
                std::cout << X;
                for(int i=0; i < 5; i++)
                    defenseBoard[X+i][Y] = 'C';
            }
        }
};