#include "Human_Player.h"

/*void Human_Player::addBattleShip(Coordinates start,Coordinates end){
        if(start.get_Y() == end.get_Y()){
            for(int i = 0; i < 5; i++ ){
                if(shipPosition[12*start.get_Y() + i] == 1)
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            pieces.emplace_back(new Battle_Ship(start,end));
        }
        if(start.get_X() == end.get_X()){
            for(int i = 0; i < 5; i++ ){
                if(shipPosition[12*i + start.get_X()]  == 1)
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            pieces.emplace_back(new Battle_Ship(start,end));
        }
};

void Human_Player::addSupportShip(Coordinates start,Coordinates end){
        if(start.get_Y() == end.get_Y()){
            for(int i = 0; i < 3; i++ ){
                if(shipPosition[12*start.get_Y()] + 1 == 1)
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            pieces.emplace_back(new Battle_Ship(start,end));
        }
        if(start.get_X() == end.get_X()){
            for(int i = 0; i < 3; i++ ){
                if(shipPosition[12*i] + start.get_X() == 1)
                    throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
            }
            pieces.emplace_back(new Battle_Ship(start,end));
        }
};

void Human_Player::addSubmarine(Coordinates start){
        if(shipPosition[12*start.get_Y()+start.get_X()]== 1){
            pieces.emplace_back(new Submarine(start));
        }else{
            throw std::invalid_argument("Coordinate non valide, una barca e' gia presente in queste coordinate");
        }
};
*/
void Human_Player::prepareBoard(){

    for (int i = 1; i < 4; i++){
        std::string input;
        std::cout << "\033[1;31mInserisci le Coordinate per la "<< i <<" corazzata (esempio: a1 a5)\033[0m"<<  std::endl;
        std::cin >> input;
        Coordinates startBoat = Coordinates(input);
        std::cin >> input;
        Coordinates endBoat = Coordinates(input);
        try{
            board->addBattleShip(startBoat,endBoat);
        }catch(std::invalid_argument e){
            std::cout << "\033[1;31mCoordinate non valide, una barca e' gia presente in queste coordinate.Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    for (int i = 1; i < 4; i++){
        std::string input;
        std::cin >> input;
        std::cout << "\033[1;31mInserisci le Coordinate per la "<< i <<" support ship (esempio: a1 a3)\033[0m"<<  std::endl;
        Coordinates startBoat = Coordinates(input);
        std::cin >> input;
        Coordinates endBoat = Coordinates(input);
        try{
            board->addSupportShip(startBoat,endBoat);
        }catch(std::invalid_argument e){
            std::cout << "\033[1;31mCoordinate non valide, una barca e' gia presente in queste coordinate.Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    for (int i = 1; i < 4; i++){
        std::string input;
        std::cout << "\033[1;31mInserisci le Coordinate per la "<< i <<" sottomarino (esempio: a1)\033[0m"<<  std::endl;
        std::cin >> input;
        Coordinates startBoat = Coordinates(input);
        try{
            board->addSubmarine(startBoat);
        }catch(std::invalid_argument e){
            std::cout << "\033[1;31mCoordinate non valide, una barca e' gia presente in queste coordinate.Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    
};
Human_Player::Human_Player(){
    prepareBoard();
}

Human_Player::~Human_Player(){
    pieces.clear();
    delete board;
}