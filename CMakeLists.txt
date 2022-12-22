cmake_minimum_required(VERSION 3.24)
project(LdP_Battleship)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LdP_Battleship
        src/Coordinates.cpp
        src/Coordinates.h
        src/Ship.h tst/test.cpp)
