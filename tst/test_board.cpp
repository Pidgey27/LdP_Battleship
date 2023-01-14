/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "src\Board.h"

static void testBoard(){
    bool check = true;
    //******************************
    //Check if singleton is correct
    Board* test = Board::getInstance();
    Board* test2 = Board::getInstance();
    if(test != test2)
        check = false;

    //******************************
    //Check if addBattleShip is correct
    // Batleship no collision
    try{
        test2->addBattleShip(Coordinates("a1"), Coordinates("e1"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 23";
        }
    
    try{
        test2->addBattleShip(Coordinates("c5"), Coordinates("g5"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 30";
        }
    
    try{
        test2->addBattleShip(Coordinates("l1"), Coordinates("l5"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 37";
        }
    
    try{
        test2->addBattleShip(Coordinates("j7"), Coordinates("j11"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 44";
        }
 
    try{
        test2->addBattleShip(Coordinates("b10"), Coordinates("f10"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 51";
        }

    // test collision
    try{
        test2->addBattleShip(Coordinates("d1"), Coordinates("d5"));
        std::cout << "error line 57";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addBattleShip(Coordinates("h9"), Coordinates("l9"));
        std::cout << "error line 62";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addBattleShip(Coordinates("c5"), Coordinates("g5"));
        std::cout << "error line 67";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addBattleShip(Coordinates("d5"), Coordinates("d9"));
        std::cout << "error line 72";
        check = false;
    }catch(std::invalid_argument e){}


    //******************************
    //Check if addSupportShip is correct
    try{
        test2->addSupportShip(Coordinates("k10"), Coordinates("k12"));     
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 83";
        }
    try{
        test2->addSupportShip(Coordinates("h2"), Coordinates("j2"));     
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 89";
        }
    try{
        test2->addSupportShip(Coordinates("h8"), Coordinates("h10"));     
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 95";
        }
    // test collisioni
    try{
        test2->addBattleShip(Coordinates("h8"), Coordinates("j8"));
        std::cout << "error line 100";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addBattleShip(Coordinates("h1"), Coordinates("h3"));
        std::cout << "error line 105";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addBattleShip(Coordinates("a8"), Coordinates("c8"));
        std::cout << "error line 110";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addBattleShip(Coordinates("a1"), Coordinates("a3"));
        std::cout << "error line 115";
        check = false;
    }catch(std::invalid_argument e){}
    
    //******************************
    //Check if addSupportShip is correct
    try{
        test2->addSubmarine(Coordinates("e3"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 125";
        }
    try{
        test2->addSubmarine(Coordinates("a6"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 131";
        }
    try{
        test2->addSubmarine(Coordinates("f7"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 137";
        }
    try{
        test2->addSubmarine(Coordinates("l12"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 143";
        }
    // test collision
    try{
        test2->addSubmarine(Coordinates("h8"));
        std::cout << "error line 148";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addSubmarine(Coordinates("i2"));
        std::cout << "error line 153";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addSubmarine(Coordinates("j10"));
        std::cout << "error line 158";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        test2->addSubmarine(Coordinates("a1"));
        std::cout << "error line 163";
        check = false;
    }catch(std::invalid_argument e){}

    //test support function
    if(test->get(Coordinates("a1")) != 'C'){
        std::cout << "error line 169: get method not working";
        check = false;
    }
    

    test->printBoard();
    test->printAtkBoard();
    test->printDefBoard();
    if(check)
        std::cout << "all Board test are successfull";
}