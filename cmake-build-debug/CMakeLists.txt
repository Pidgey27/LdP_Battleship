cmake_minimum_required(VERSION 3.23)
project(LdP_Battleship)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LdP_Battleship
        Coordinates.h
        Ship.h
        Coordinates.cpp
)