#include <iostream>
using namespace std;
#include "trajectoire.h"

int main()
{
    std::vector<float> position_ini;
    position_ini.push_back(1.);
    position_ini.push_back(1.);
    Trajectoire T(position_ini);
    T.simule(30);
    return 0;
}
