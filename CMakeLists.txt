cmake_minimum_required(VERSION 3.24)
project(LdP_Battleship)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LdP_Battleship
        src/Coordinates.cpp
        src/Ship.cpp 
        src/Submarine.cpp 
        src/Support_Ship.cpp 
        src/Battle_Ship.cpp
        src/Board.cpp

        src/main.cpp 
        
        tst/test_coordinates.cpp
        tst/test_board.cpp)
