//
// Created by Alessandra Villarà on 14/01/2023.
// matricola 1137125

#include <vector>
#include <iostream>

static void test_vector(){
    std::vector<int> prova{0, 1, 2, 3, 4, 5};
    for(int i=0; i<prova.size(); i++)
        std::cout<<prova[i]<<" ";
    std::cout<<std::endl<<"voglio eliminare il 3, quindi testo il metodo erase di vector "<<prova[3]<<std::endl;
    prova.erase(prova.begin()+3);
    for(int i=0; i<prova.size(); i++)
        std::cout<<prova[i]<<" ";
}
