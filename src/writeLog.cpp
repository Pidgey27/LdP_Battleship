//
// Created by Damiano Marconato
//  matr 1221875
//

#include "writeLog.h"
#include <chrono>

writeLog::writeLog(std::string s){
    std::fstream fs;
    fs.open("test.txt", std::ios::out | std::ios::app);
    fs << s << std::endl;
    fs.close();
}

writeLog::writeLog(std::string nameShip, std::string s1,std::string s2){
    std::fstream fs;
    fs.open("test.txt", std::ios::out | std::ios::app);
    fs << nameShip << " " << s1 << " - " << s2 << std::endl;
    fs.close();
}

