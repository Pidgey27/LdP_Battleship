#include "Replay.h"
#include "Game_Master.h"
#include <vector>


Replay::Replay(){
    std::vector<std::string> coord_P1;
    std::vector<std::string> coord_P2;
    std::string line;
    std::ifstream myfile ("replay.txt");
    int maxIstanceShip = 0;
    bool IsInstantiated = false;

    if (myfile.is_open())
    {
        
        while ( getline (myfile,line) || maxIstanceShip == 16)
        {
            
                if(maxIstanceShip < 8)
                    coord_P1.push_back(line);
                else if (maxIstanceShip > 7 && maxIstanceShip < 16)
                    coord_P2.push_back(line);
                maxIstanceShip ++;   
                 
        }

        Game_Master gm(coord_P1,coord_P2);
        
        myfile.close();
    }

    else std::cout << "Unable to open file"; 

}
