#include <iostream>
using namespace std;
#include "trajectoire.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int main()
{


    std::vector<float> position_ini;
    position_ini.push_back(1.4);
    Trajectoire T(position_ini);
    T.simule(200);
    T.afficher();

    return 0;
}
