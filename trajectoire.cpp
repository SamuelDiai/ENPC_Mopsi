#include "trajectoire.h"
#include <iostream>
float potentiel(std::vector<float> coords)
{
    return sin(coords[0]);
}
std::vector<float> gradient(std::vector<float> coords)
{
    std::vector<float> res;
    for(int i=0;i<coords.size();i++)
    {
        std::vector<float> epsilon;
        epsilon.resize(coords.size());
        for(int j=0;j<coords.size();j++)
        {
            epsilon[j]=0;
        }
        epsilon[i]=1e-5;
        res.push_back((potentiel(coords+epsilon)-potentiel(coords-epsilon))/(2*1e-5));

    }
    return res;
}

std::vector<float> operator+(std::vector<float> vec1,std::vector<float> vec2)
{
    assert(vec1.size()==vec2.size());
    std::vector<float> res;
    res.resize(vec1.size());
    for (int i=0;i<vec1.size();i++)
    {
        res[i]=vec1[i]+vec2[i];
    }
    return res;
}

std::vector<float> operator-(std::vector<float> vec1,std::vector<float> vec2)
{
    assert(vec1.size()==vec2.size());
    std::vector<float> res;
    res.resize(vec1.size());
    for (int i=0;i<vec1.size();i++)
    {
        res[i]=vec1[i]-vec2[i];
    }
    return res;
}


std::vector<float>operator*(float coef,std::vector<float> vec)
{
    std::vector<float> res;
    res.resize(vec.size());
    for (int i=0;i<vec.size();i++)
    {
        res[i]=coef*vec[i];
    }
    return res;
}

void Trajectoire::actualise()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    int dim = position_initiale.size();
    std::vector<float> G;
    std::vector<float> last = list[list.size()-1];
    for (int i = 0;i<dim;i++)
    {
        std::normal_distribution<float> distribution( 0 , sqrt(dt));
        G.push_back(sqrt(2*kb*T)*distribution(gen));
    }

    std::vector<float> update = last + G + (-dt)*gradient(last);
    list.push_back(update);

}

void Trajectoire::simule(int N)
{
    for( int i=0;i<N;i++)
    {
        actualise();
    }
}

void Trajectoire::afficher()
{
    for( int i=0;i<list.size();i++)
    {
        std::cout<<(list[i])[0]<<std::endl;
    }
}
