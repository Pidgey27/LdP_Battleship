//
// Created by Alessandra Villarà on 09/01/2023.
// matricola 1137125

#include "Player.h"
//search ship does first a search on the name, then on the coordinates. THe first instance searches for a match on center
//coordinates of the ship, then searches on the coordinates occupied by the ship.
int Player::search_For_Ship(Coordinates coord, char name) {
    for(int i=0; i<pieces.size(); i++) {
        if (pieces[i].get_Name() == name && pieces[i].get_Center_X() == coord.get_X() &&
            pieces[i].get_Center_Y() == coord.get_Y())
            return i;
        if (pieces[i].get_Name() == name && pieces[i].get_Center_X() == coord.get_X() && name != 'E') {
            int j = pieces[i].get_Center_Y() - ((pieces[i].get_Dimension() - 1) / 2);
            int end = j + pieces[i].get_Dimension();
            for (j; j <= end; j++)
                if (j == coord.get_Y())
                    return i;
        }
        if (pieces[i].get_Name() == name && pieces[i].get_Center_Y() == coord.get_Y() && name != 'E') {
            int j = pieces[i].get_Center_X() - ((pieces[i].get_Dimension() - 1) / 2);
            int end = j + pieces[i].get_Dimension();
            for (j; j <= end; j++)
                if (j == coord.get_X())
                    return i;
        }
    }

    throw new std::runtime_error("Non ho trovato la nave richiesta, è stato commesso qualche errore");
}

void Player::remove_Ship(int i) {
    pieces.erase(pieces.begin()+i);
}
