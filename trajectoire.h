#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H
#include <assert.h>
#include <vector>
#include <random>

// Potentiel
float potentiel(std::vector<float> coords);

// Gradient
std::vector<float> gradient(std::vector<float> coords);

// Constantes
const float dt=0.1;
const float T= 300;
const float kb = 1.38e-23;

std::vector<float> operator+(std::vector<float> vec1,std::vector<float> vec2);
std::vector<float> operator-(std::vector<float> vec1,std::vector<float> vec2);
std::vector<float> operator*(float coef,std::vector<float> vec);



//Trajectoire
class Trajectoire
{
    std::vector<float> position_initiale;
    std::vector<std::vector<float> > list;
public:
    Trajectoire(std::vector<float> position){position_initiale = position;
                                    list.resize(1);
                                    list.push_back(position);}
    void actualise();
    void simule(int N);

};

#endif // TRAJECTOIRE_H
