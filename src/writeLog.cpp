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


