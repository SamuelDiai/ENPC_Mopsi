#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "funcs.h"
#include "trajectoire.h"

std::vector<std::vector<float> > simulate()
{
    std::vector<std::vector<float> > res;
    std::vector<float> position_ini;
    position_ini.push_back(0);
    position_ini.push_back(0);
    
    Trajectoire T(position_ini);
    T.simule(5000);
    for (int i=0;i<T.get_size();i++)
        res.push_back(T.position(i));
        
    return res;

};
