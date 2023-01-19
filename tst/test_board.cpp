/********************************************
 *          Pietro Galiazzo 1216517         *
 ********************************************/

#include "src\Board.h"

static void testBoard(){
    bool check = true;
    std::cout << "Board Test" << std::endl;
    Board testboard = Board();

    //******************************
    //Check if addBattleShip is correct
    // Batleship no collision
    try{
        testboard.addBattleShip(Coordinates("a1"), Coordinates("e1"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 23";
        }
    try{
        testboard.addBattleShip(Coordinates("c5"), Coordinates("g5"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 30";
        }
    try{
        testboard.addBattleShip(Coordinates("l1"), Coordinates("l5"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 37";
        } 
    try{
        testboard.addBattleShip(Coordinates("j7"), Coordinates("j11"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 44";
        }
    try{
        testboard.addBattleShip(Coordinates("b10"), Coordinates("f10"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 51";
        }
    //******************************
    // test collision
    try{
        testboard.addBattleShip(Coordinates("d1"), Coordinates("d5"));
        std::cout << "error line 57";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addBattleShip(Coordinates("h9"), Coordinates("l9"));
        std::cout << "error line 62";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addBattleShip(Coordinates("c5"), Coordinates("g5"));
        std::cout << "error line 67";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addBattleShip(Coordinates("d5"), Coordinates("d9"));
        std::cout << "error line 72";
        check = false;
    }catch(std::invalid_argument e){}

    //******************************
    //Check if addSupportShip is correct
    try{
        testboard.addSupportShip(Coordinates("k10"), Coordinates("k12"));     
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 83";
        }
    try{
        testboard.addSupportShip(Coordinates("h2"), Coordinates("j2"));     
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 89";
        }
    try{
        testboard.addSupportShip(Coordinates("h8"), Coordinates("h10"));     
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 95";}
    try{
        testboard.addSupportShip(Coordinates("a8"), Coordinates("c8"));
    }catch(std::invalid_argument e){
        std::cout << "error line 100";
        check = false;}
    // test collisioni
    try{
        testboard.addSupportShip(Coordinates("h8"), Coordinates("j8"));
        std::cout << "error line 105";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addSupportShip(Coordinates("h1"), Coordinates("h3"));
        std::cout << "error line 110";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addSupportShip(Coordinates("a1"), Coordinates("a3"));
        std::cout << "error line 115";
        check = false;
    }catch(std::invalid_argument e){}
    
    //******************************
    //Check if addSupportShip is correct
    try{
        testboard.addSubmarine(Coordinates("e3"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 125";
        }
    try{
        testboard.addSubmarine(Coordinates("a6"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 131";
        }
    try{
        testboard.addSubmarine(Coordinates("f7"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 137";
        }
    try{
        testboard.addSubmarine(Coordinates("l12"));
    }catch(std::invalid_argument e){
        check = false;
        std::cout << "error line 143";
        }
    //******************************
    // test collision
    try{
        testboard.addSubmarine(Coordinates("h8"));
        std::cout << "error line 148";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addSubmarine(Coordinates("i2"));
        std::cout << "error line 153";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addSubmarine(Coordinates("j10"));
        std::cout << "error line 158";
        check = false;
    }catch(std::invalid_argument e){}
    try{
        testboard.addSubmarine(Coordinates("a1"));
        std::cout << "error line 163";
        check = false;
    }catch(std::invalid_argument e){}
    //******************************
    //test support function
    if(testboard.get(Coordinates("a1")) != 'C'){
        std::cout << "error line 169: get method not working";
        check = false;
    }


    std::cout << std::endl;
    testboard.printBoard();
    //test.printAtkBoard();
    //test.printDefBoard();
    if(check)
        std::cout << "all Board test are successfull" << std::endl;
}