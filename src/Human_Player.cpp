/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/
#include "Human_Player.h"

#define CHECK_IF_INPUT_ARE_SHIP_CENTER_BATTLESHIP ((battleship.at(i).get_Center_X() == origin.get_X()) && (battleship.at(i).get_Center_Y() == origin.get_Y()))
#define CHECK_IF_INPUT_ARE_SHIP_CENTER_SUPPORT ((support.at(i).get_Center_X() == origin.get_X()) && (support.at(i).get_Center_Y() == origin.get_Y()))
#define CHECK_IF_INPUT_ARE_SHIP_CENTER_SUBMARINE ((submarine.at(i).get_Center_X() == origin.get_X()) && (submarine.at(i).get_Center_Y() == origin.get_Y()))

Human_Player::Human_Player(){
    prepareBoard();
}

void Human_Player::prepareBoard(){
    for (int i = 1; i < 4; i++){
        std::string log = "P1";
        try{
            std::string input;
            std::cout << "\033[1;34mInserisci le Coordinate per la "<< i <<" corazzata (esempio: a1 a5)\033[0m"<<  std::endl;
            std::cin >> input;
            Coordinates startBoat = Coordinates(input);
            log = log + " " + input;
            std::cin >> input;
            Coordinates endBoat = Coordinates(input);
            log = log + " " + input;
            if(checkBattleShip(startBoat, endBoat)){
                try{
                    board.addBattleShip(startBoat,endBoat);
                }catch(std::invalid_argument e){
                    std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;
                    i--;
                    continue;
                }
                Battle_Ship test(startBoat, endBoat);
                battleship.push_back(std::move(test));
                std::cout << "test if here line 3" << std::endl;
                std::cout << log << std::endl;
                writeLog wl(log);
            }else{
                std::cout << "\033[1;31mLe coordinate non rispettano la dimensione di una Corazzata. Riprova\033[0m"<<  std::endl;
                i--;
            }
        }catch(std::runtime_error e){
            std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;
            i--;
        }
        std::cout << "test if here line 40" << std::endl; 
    }
    for (int i = 1; i < 4; i++){
        std::string log = "P1";
        try{
            std::string input;
            std::cout << "\033[1;34mInserisci le Coordinate per la "<< i <<" support ship (esempio: a1 a3)\033[0m"<<  std::endl;
            std::cin >> input;
            Coordinates startBoat = Coordinates(input);
            log = log + " " + input;
            std::cin >> input;
            Coordinates endBoat = Coordinates(input);
            log = log + " " + input;
            if(checkSupportShip(startBoat, endBoat)){
                try{
                    board.addSupportShip(startBoat,endBoat);
                }catch(std::invalid_argument e){
                    std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;
                    i--;
                    continue;
                }
                Support_Ship ship(startBoat, endBoat, true);
                support.push_back(std::move(ship)); 
            }else{
                std::cout << "\033[1;31mLe coordinate non rispettano la dimensione di una Nave da Supporto. Riprova\033[0m"<<  std::endl;
                i--;
            }
        }catch(std::runtime_error e){
            std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;
            i--;
        }
        writeLog wl(log);
    }
    for (int i = 1; i < 3; i++){
        std::string log = "P1";
        try{
            std::string input;
            std::cout << "\033[1;34mInserisci le Coordinate per la "<< i <<" sottomarino (esempio: a1)\033[0m"<<  std::endl;
            std::cin >> input;
            Coordinates startBoat = Coordinates(input);
            log = log + " " + input;
            try{
                submarine.push_back(Submarine(startBoat));
                board.addSubmarine(startBoat);
            }catch(std::invalid_argument e){
                std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;
                i--;
            }
        }catch(std::runtime_error e){
            std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;
            i--;
        }
        writeLog wl(log);
    }
    // todo delete this line
    board.printBoard();
};

std::string Human_Player::check_Input_Coordinate(){
    std::string input;
    std::string output;
    std::string coordinates1;
    std::string coordinates2;
    bool flag = true;
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
    Coordinates target = Coordinates(coordinates2);
    for(int i = 0; i < battleship.size(); i++){
        if(CHECK_IF_INPUT_ARE_SHIP_CENTER_BATTLESHIP){
            return output;
        }else{
            flag = false; 
        }
    }
    for(int i = 0; i < support.size(); i++){
        if(CHECK_IF_INPUT_ARE_SHIP_CENTER_SUPPORT){
            return output;
        }else{
            flag = false; 
        }
    }
    for(int i = 0; i < submarine.size(); i++){
        if(CHECK_IF_INPUT_ARE_SHIP_CENTER_SUBMARINE){
            return output;
        }else{
            flag = false; 
        }
    }
    if(flag == false){
        throw std::invalid_argument("La prima coordinata non e' il centro della barca");
    }
    check_Target_Coordinate(target);
}

std::string Human_Player::get_Coordinates_to_Move(){
    for(int i = 0; i < 1; i++){
        try{
            std::string playerMove = check_Input_Coordinate();
            return playerMove;
        }catch(std::invalid_argument &e){
            i--;
            std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;
        }catch(std::runtime_error &e){
            std::cout << "\033[1;31m" << e.what() << ". Riprova\033[0m"<<  std::endl;

        }
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

bool Human_Player::check_Target_Coordinate(Coordinates target){
    return false;
}
