/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "Board.h"

    Board::Board(){
        for(int i = 0; i < 12; i++){
            for(int j  =0; j < 12; j ++){ 
            defenseBoard[i][j] = ' ';
            attackBoard[i][j] = ' ';
            }
        }
    }

//--------------------------------------------printing function---------------------------
void Board::printDefBoard(){

    std::cout << "      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|" <<  std::endl;
    std::cout << "      -----------------------------------------------" <<std::endl;
    for(int i = 0; i < 12; i ++) { //column loop
        char C = 65 + i;
        std::cout << "  "  << C << "   ";
        for(int j  =0; j < 12; j ++){ //row loop
            switch(this->defenseBoard[i][j]){
            case('C'):
                std::cout << this->defenseBoard[i][j]  << " | ";
                break;
            case('S'):
                std::cout  << this->defenseBoard[i][j] <<  " | ";
                break;
            case('E'):
                std::cout << this->defenseBoard[i][j] <<  " | ";
                break;
            default:
                std::cout << this->defenseBoard[i][j] << " | ";
                break;
            }
        }
        std::cout << std::endl; //new line at end of column
        std::cout <<"     ------------------------------------------------";
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

void Board::printAtkBoard(){

        std::cout << "\033[1;36m      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|\033" << std::endl << std::endl;
    for(int i = 0; i < 12; i ++) { //column loop
        char C = 65 + i;
        std::cout << "  \033[1;36m"  << C << "\033[0m   ";
        for(int j  =0; j < 12; j ++){ //row loop
            switch(this->attackBoard[i][j]){
            case('X'):
                std::cout << "\033[1;31m" << this->attackBoard[i][j] << "\033[0m" << " | ";
                break;
            case('O'):
                std::cout << "\033[1;34m" << this->attackBoard[i][j] << "\033[0m" << " | ";
                break;
            case('Y'):
                std::cout << "\033[1;33m" << this->attackBoard[i][j] << "\033[0m" << " | ";
                break;
            default:
                std::cout << this->attackBoard[i][j] << " | ";
                break;
            }
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
            default:
                std::cout << this->defenseBoard[i][j] << " | ";
                break;
            }
        }
        std::cout <<"     ";
        std::cout << "  \033[1;36m"  << C << "\033[0m   ";
        for(int j  =0; j < 12; j ++){ //row loop 2 table  
            switch(this->attackBoard[i][j]){
            case('X'):
                std::cout << "\033[1;31m" << this->attackBoard[i][j] << "\033[0m" << " | ";
                break;
            case('O'):
                std::cout << "\033[1;34m" << this->attackBoard[i][j] << "\033[0m" << " | ";
                break;
            case('Y'):
                std::cout << "\033[1;33m" << this->attackBoard[i][j] << "\033[0m" << " | ";
                break;
            default:
                std::cout << this->attackBoard[i][j] << " | ";
                break;
            }
        }

        std::cout << std::endl; //new line at end of column
        std::cout <<"     ------------------------------------------------           ------------------------------------------------";
        std::cout << std::endl;
    
    
    }
    std::cout << std::endl;
};

//------------------------------------------draw and check boat function-------------------------
void Board::addBattleShip(Coordinates start,Coordinates end){
        if(start.get_Y() == end.get_Y()){
            for(int i = 0; i < 5; i++ ){
                if(defenseBoard[end.get_Y()][start.get_X()+i] != ' ')
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            for(int i = 0; i < 5; i++ ){
                defenseBoard[end.get_Y()][start.get_X()+i] = 'C';
            }
        }
        if(start.get_X() == end.get_X()){
            for(int i = 0; i < 5; i++ ){
                if(defenseBoard[start.get_Y()+i][start.get_X()] != ' ')
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            for(int i = 0; i < 5; i++ ){
                defenseBoard[start.get_Y()+i][start.get_X()] = 'C';
            }
        }
};

void Board::addSupportShip(Coordinates start,Coordinates end){
        if(start.get_Y() == end.get_Y()){
            for(int i = 0; i < 3; i++ ){
                    if(defenseBoard[end.get_Y()][start.get_X()+i] != ' ')
                        throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
                }
            for(int i = 0; i < 3; i++ ){
                defenseBoard[end.get_Y()][start.get_X()+i] = 'S';
            }
        }
        if(start.get_X() == end.get_X()){
            for(int i = 0; i < 3; i++ ){
                        if(defenseBoard[start.get_Y()+i][start.get_X()] != ' ')
                            throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
                    }
            for(int i = 0; i < 3; i++ ){
                defenseBoard[start.get_Y()+i][start.get_X()] = 'S';
            }
        }
};

void Board::addSubmarine(Coordinates start){
        if(defenseBoard[start.get_Y()][start.get_X()] == ' '){
            defenseBoard[start.get_Y()][start.get_X()] = 'E';
        }else{
            throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
        }
};

//-------------------------------------------Public function----------------------------

void Board::clearHit(){
    for(int i = 0; i < 12; i ++) { //column loop
        for(int j  =0; j < 12; j ++){ //row loop
             if(attackBoard[i][j] == 'O')
                attackBoard[i][j] = ' ';
        }
    }
};
 
void Board::clearScan(){
    for(int i = 0; i < 12; i ++) { //column loop
        for(int j  =0; j < 12; j ++){ //row loop
        if(attackBoard[i][j] == 'Y')
            attackBoard[i][j] = ' ';
        }
    }
};

char Board::get(Coordinates coor){
    return {defenseBoard[coor.get_Y()][coor.get_X()]};
};

void Board::write_On_Attack_Board(Coordinates coordinate,char input){
    attackBoard[coordinate.get_Y()][coordinate.get_X()] = input;
};

void Board::write_On_Defense_Board(Coordinates coordinate, char input){
    defenseBoard[coordinate.get_Y()][coordinate.get_X()] = input;
};

/*bool Board::shot(Coordinates coor){
    char tiles = defenseBoard[coor.get_Y()][coor.get_X()];
    if(tiles == 'C' || tiles == 'S' || tiles == 'E'){
        defenseBoard[coor.get_Y()][coor.get_X()] = 'X';
        return true;
    }
    defenseBoard[coor.get_Y()][coor.get_X()] = 'O';
    return false;
};

bool Board::exploring(Coordinates coor){
    int pos2 = coor.get_X()-2;
    int pos1 = coor.get_Y()-2;
    bool checks = false;
    int i = 0;
    int j = 0;
    for(i ; i < 5; i++){
        for(j ; j < 5; j++){
            if(pos1+i == 13)
                return checks;
            if(pos2+j == 13)
                continue;
            if( this->defenseBoard[pos1+i][pos2+j] == 'C' || this->defenseBoard[pos1+i][pos2+j] == 'S' || this->defenseBoard[pos1+i][pos2+j] == 'E'){
                this->attackBoard[pos1+i][pos2+j] == 'Y';
                checks = true;
            }
        }
    }
    return checks;
}*/