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

}