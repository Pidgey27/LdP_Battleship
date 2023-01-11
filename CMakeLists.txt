cmake_minimum_required(VERSION 3.24)
project(LdP_Battleship)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LdP_Battleship
        src/Coordinates.cpp
        src/Submarine.cpp
        src/Support_Ship.cpp 
        src/Battle_Ship.cpp
        src/Board.cpp

        src/main.cpp 
        
        tst/test_coordinates.cpp
        tst/test_board.cpp src/Player.h src/Player.cpp src/Com_Player.h src/Com_Player.cpp tst/test_Com_Player.cpp src/Game_Master.h src/Game_Master.cpp)
