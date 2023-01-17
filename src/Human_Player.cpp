/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/
#include "Human_Player.h"

void Human_Player::prepareBoard(){
    for (int i = 1; i < 4; i++){
        try{
            std::string input;
            std::cout << "\033[1;34mInserisci le Coordinate per la "<< i <<" corazzata (esempio: a1 a5)\033[0m"<<  std::endl;
            std::cin >> input;
            Coordinates startBoat = Coordinates(input);
            std::cin >> input;
            Coordinates endBoat = Coordinates(input);
            if(checkBattleShip(startBoat, endBoat)){
                try{
                    board->addBattleShip(startBoat,endBoat);
                }catch(std::invalid_argument e){
                    std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
                    i--;
                    continue;
                }
                pieces.emplace_back(new Battle_Ship(startBoat, endBoat));
            }else{
                std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
                i--;
            }
        }catch(std::runtime_error e){
            std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    for (int i = 1; i < 4; i++){
        try{
            std::string input;
            std::cout << "\033[1;34mInserisci le Coordinate per la "<< i <<" support ship (esempio: a1 a3)\033[0m"<<  std::endl;
            std::cin >> input;
            Coordinates startBoat = Coordinates(input);
            std::cin >> input;
            Coordinates endBoat = Coordinates(input);
            if(checkSupportShip(startBoat, endBoat)){
                try{
                    board->addSupportShip(startBoat,endBoat);
                }catch(std::invalid_argument e){
                    std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
                    i--;
                    continue;
                }
                pieces.emplace_back(new Support_Ship(startBoat, endBoat));
                
            }else{
                std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
                i--;
            }
        }catch(std::runtime_error e){
            std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    for (int i = 1; i < 3; i++){
        try{
            std::string input;
            std::cout << "\033[1;34mInserisci le Coordinate per la "<< i <<" sottomarino (esempio: a1)\033[0m"<<  std::endl;
            std::cin >> input;
            Coordinates startBoat = Coordinates(input);
            try{
                Submarine* ship = new Submarine(startBoat);
                pieces.emplace_back(ship);
                board->addSubmarine(startBoat);
            }catch(std::invalid_argument e){
                std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
                i--;
            }
        }catch(std::runtime_error e){
            std::cout << "\033[1;31mCoordinate non valide. Riprova\033[0m"<<  std::endl;
            i--;
        }
    }
    // todo delete this line
    board->printBoard();
};

Human_Player::Human_Player(){
    prepareBoard();
}

std::string Human_Player::get_Coordinates_to_Move(){
    std::string input;
    std::string output;
    std::string coordinates1;
    std::string coordinates2;
    try{
        std::cout << "\033[1;34mInserisci un comando di gioco(esempio: a1 g10)\033[0m"<<  std::endl;
        std::cin >> input;
        output = input;
        coordinates1 = input;
        std::cin >> input;
        coordinates2 = input;
        output = output + " " + input;
        if(coordinates1 == "AA" & coordinates2 == "AA")
            return output;
        else if(coordinates1 == "XX" & coordinates2 == "XX")
            return output;
        else if(coordinates1 == "OO" & coordinates2 == "OO")
            return output;
        else if(coordinates1 == "aa" & coordinates2 == "aa")
            return output;
        else if(coordinates1 == "xx" & coordinates2 == "xx")
            return output;
        else if(coordinates1 == "oo" & coordinates2 == "oo")
            return output;
        Coordinates origin = Coordinates(coordinates1);
        try{
            search_For_Ship(origin, 'B');
        }catch(std::runtime_error e){
            try{
                search_For_Ship(origin, 'S');
            }catch(std::runtime_error e){
                try{
                    search_For_Ship(origin, 'E');
                }catch(std::runtime_error e){
                    std::cout << "\033[1;31m Comando non valido\033[0m"<<  std::endl;
                    return "";
                }
            }
        }
        return output;
    }catch(std::runtime_error e){  
        std::cout << "\033[1;31m Coordinate non valide\033[0m"<<  std::endl;
        return "";
    }
}

bool Human_Player::checkBattleShip(Coordinates first, Coordinates last){ 
    if((first.get_X() == last.get_X()) && (abs(last.get_Y() - first.get_Y()) == 4)){
        return true;
    }else if ((first.get_Y() == last.get_Y()) && (abs(last.get_X() - first.get_X()) == 4)){
        return true;
    }
    return false;
}

bool Human_Player::checkSupportShip(Coordinates first, Coordinates last){ 
    if((first.get_X() == last.get_X()) && (abs(last.get_Y() - first.get_Y()) == 2)){
        return true;
    }else if ((first.get_Y() == last.get_Y()) && (abs(last.get_X() - first.get_X()) == 2)){
        return true;
    }
    return false;
}

Human_Player::~Human_Player(){
    pieces.clear();
}