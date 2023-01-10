/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "Board.h"

Board* Board ::instancePtr = NULL;

    //TODO : constructor have to initialize the board with boat
    Board::Board(){
        for(int i = 0; i < 12; i++){
            for(int j  =0; j < 12; j ++){ 
            this->defenseBoard[i][j].tiles = ' ';
            this->attackBoard[i][j].tiles = ' ';
            }
        }
        addBattleShip();

    }

void Board::printDefBoard(){

    std::cout << "      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|" << std::endl << std::endl;

    for(int i = 0; i < 12; i ++) { //column loop
        char C = 65 + i;
        if((65+i) == 74 || (65+i) == 75 || (65+i) == 76)
            C = 67 + i;
        std::cout << "  "  << C << "   ";
        for(int j  =0; j < 12; j ++){ //row loop
            std::cout << this->defenseBoard[i][j].tiles << " | ";
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
            std::cout << this->attackBoard[i][j].tiles << " | ";
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
        for(int j  = 0; j < 12; j ++){ //row loop
            std::cout << this->defenseBoard[i][j].tiles << " | ";
        }
        std::cout <<"     ";
        std::cout << "  \033[1;36m"  << C << "\033[0m   ";
        for(int j  =0; j < 12; j ++){ //row loop 2 table
            std::cout << this->attackBoard[i][j].tiles << " | ";
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
        for(int i : {1,2,3}){
            std::cout << "\033[1;31mInserisci le Coordinate della " << i << " corazzata (esempio: a1 a5)\033[0m"<<  std::endl;
            std::cin >> input;
            Coordinates coorStart = Coordinates(input);
            std::cin >> input;
            Coordinates coorEnd = Coordinates(input);
            if(coorStart.get_Y() == coorEnd.get_Y())
                for(int i = 0; i < 5; i++ ){
                    this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i].tiles = 'C';
                    if(i == 2)
                        this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i].bb = Battle_Ship(coorStart,coorEnd);
                }
            if(coorStart.get_X() == coorEnd.get_X())
                for(int i = 0; i < 5; i++ ){
                    this->defenseBoard[i][coorEnd.get_X()].tiles = 'C';
                    if(i == 2)
                        this->defenseBoard[coorEnd.get_Y()][i].bb = Battle_Ship(coorStart,coorEnd);
                }
        }
};