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

//------------------------------------------draw and check boat function-------------------------
void Board::addBattleShip(Coordinates start,Coordinates end){
    Battle_Ship(start,end);
        if(start.get_Y() == end.get_Y()){
            for(int i = 0; i < 5; i++ ){
                if(this->defenseBoard[end.get_Y()][start.get_X()+i] != ' ')
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            for(int i = 0; i < 5; i++ ){
                this->defenseBoard[end.get_Y()][start.get_X()+i] = 'C';
            }
        }
        if(start.get_X() == end.get_X()){
            for(int i = 0; i < 5; i++ ){
                if(this->defenseBoard[start.get_Y()+i][start.get_X()] != ' ')
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            for(int i = 0; i < 5; i++ ){
                this->defenseBoard[start.get_Y()+i][start.get_X()] = 'C';
            }
        }
};

void Board::addSupportShip(Coordinates start,Coordinates end){
        if(start.get_Y() == end.get_Y()){
            for(int i = 0; i < 3; i++ ){
                    if(this->defenseBoard[end.get_Y()][start.get_X()+i] != ' ')
                        throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
                }
            for(int i = 0; i < 3; i++ ){
                this->defenseBoard[end.get_Y()][start.get_X()+i] = 'S';
            }
        }
        if(start.get_X() == end.get_X()){
            for(int i = 0; i < 3; i++ ){
                        if(this->defenseBoard[start.get_Y()+i][start.get_X()] != ' ')
                            throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
                    }
            for(int i = 0; i < 3; i++ ){
                this->defenseBoard[start.get_Y()+i][start.get_X()] = 'S';
            }
        }
};

void Board::addSubmarine(Coordinates start){
        if(this->defenseBoard[start.get_Y()][start.get_X()] == ' '){
            this->defenseBoard[start.get_Y()][start.get_X()] = 'E';
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
    return defenseBoard[coor.get_X()][coor.get_Y()];
};

/*bool Board::Shot(Coordinates coor){
    char tiles = this->defenseBoard[coor.get_X()][coor.get_Y()];
    if(tiles == 'C' || tiles == 'S' || tiles == 'E'){
        this->defenseBoard[coor.get_X()][coor.get_Y()] = 'X';
        return true;
    }
    this->defenseBoard[coor.get_X()][coor.get_Y()] = 'O';
    return false;
};

bool Board::Exploring(Coordinates coor){
    int pos1 = coor.get_X()-2;
    int pos2 = coor.get_Y()-2;
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
