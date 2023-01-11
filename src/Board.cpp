/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "Board.h"

Board* Board ::instancePtr = NULL;

    Board::Board(){
        for(int i = 0; i < 12; i++){
            for(int j  =0; j < 12; j ++){ 
            this->defenseBoard[i][j] = ' ';
            this->attackBoard[i][j] = ' ';
            }
        }
        prepareBoard();
    }

//--------------------------------------------printing function---------------------------
void Board::printDefBoard(){

    std::cout << "      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|" << std::endl << std::endl;

    for(int i = 0; i < 12; i ++) { //column loop
        char C = 65 + i;
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
        std::cout << "  \033[1;36m"  << C << "\033[0m   ";
        for(int j  = 0; j < 12; j ++){ //row loop
            switch(this->defenseBoard[i][j]){
            case('C'):
                std::cout << "\033[1;35m" << this->defenseBoard[i][j] << "\033[0m" << " | ";
                break;
            case('S'):
                std::cout << "\033[1;32m" << this->defenseBoard[i][j] << "\033[0m" << " | ";
                break;
            case('E'):
                std::cout << "\033[1;33m" << this->defenseBoard[i][j] << "\033[0m" << " | ";
                break;
            case(' '):
                std::cout << this->defenseBoard[i][j] << " | ";
                break;
            }
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

//------------------------------------------Constructor function-------------------------
void Board::addBattleShip(int i){
        std::string input;
        std::cout << "\033[1;31mInserisci le Coordinate della " << i << " corazzata (esempio: a1 a5)\033[0m"<<  std::endl;
        std::cin >> input;
        Coordinates coorStart = Coordinates(input);
        std::cin >> input;
        Coordinates coorEnd = Coordinates(input);
        if(coorStart.get_Y() == coorEnd.get_Y()){
            for(int i = 0; i < 5; i++ ){
                if(this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i] != ' ')
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            for(int i = 0; i < 5; i++ ){
                this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i] = 'C';
            }
        }
        if(coorStart.get_X() == coorEnd.get_X()){
            for(int i = 0; i < 5; i++ ){
                if(this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i] != ' ')
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            for(int i = 0; i < 5; i++ ){
                this->defenseBoard[i][coorEnd.get_X()] = 'C';
            }
        }
};

void Board::addSupportShip(int i){
        std::string input;
        std::cout << "\033[1;31mInserisci le Coordinate della " << i << " nave di supporto (esempio: a1 a3)\033[0m"<<  std::endl;
        std::cin >> input;
        Coordinates coorStart = Coordinates(input);
        std::cin >> input;
        Coordinates coorEnd = Coordinates(input);
        if(coorStart.get_Y() == coorEnd.get_Y())
            for(int i = 0; i < 3; i++ ){
                    if(this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i] != ' ')
                        throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
                }
            for(int i = 0; i < 3; i++ ){
                this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i] = 'S';
            }
        if(coorStart.get_X() == coorEnd.get_X())
            for(int i = 0; i < 3; i++ ){
                        if(this->defenseBoard[coorEnd.get_Y()][coorStart.get_X()+i] != ' ')
                            throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
                    }
            for(int i = 0; i < 3; i++ ){
                this->defenseBoard[i][coorEnd.get_X()] = 'S';
            }
};

void Board::addSubmarine(int i){
        //TODO : try and catch of exception "input wrong"
        std::string input;
        std::cout << "\033[1;31mInserisci la Coordinata del " << i << " sottomarino (esempio: a1)\033[0m"<<  std::endl;
        std::cin >> input;
        Coordinates coor = Coordinates(input);
        if(this->defenseBoard[coor.get_Y()][coor.get_X()] == ' '){
            this->defenseBoard[coor.get_Y()][coor.get_X()] = 'E';
        }else{
            throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
        }
};

void Board::prepareBoard(){
    for (int i = 1; i < 4; i++){
        try{
            addBattleShip(i);
        }catch(std::invalid_argument e){
            std::cout << "\033[1;31mCoordinate non valide, una barca e' gia presente in queste coordinate.Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    for (int i = 1; i < 4; i++){
        try{
            addSupportShip(i);
        }catch(std::invalid_argument e){
            std::cout << "\033[1;31mCoordinate non valide, una barca e' gia presente in queste coordinate.Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    for (int i = 1; i < 4; i++){
        try{
            addSubmarine(i);
        }catch(std::invalid_argument e){
            std::cout << "\033[1;31mCoordinate non valide, una barca e' gia presente in queste coordinate.Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    
};