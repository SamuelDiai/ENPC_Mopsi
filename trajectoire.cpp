#include "trajectoire.h"

float potentiel(std::vector<float> coords)
{
    return sin(coords[0])*cos(coords[1]);
}
std::vector<float> gradient(std::vector<float> coords)
{
    std::vector<float> res;
    res.resize(coords.size());
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
    for (int i=0;i<vec.size();i++)
    {
        res[i]=coef*vec[i];
    }
    return res;
}

void Trajectoire::actualise()
{
    std::default_random_engine generator;
    int dim = position_initiale.size();
    std::vector<float> G;
    G.resize(dim);
    std::vector<float> last = list[list.size()-1];
    for (int i = 0;i<dim;i++)
    {
        std::normal_distribution<float> distribution( 0 , sqrt(dt));
        G.push_back( sqrt(2*kb*T)*distribution(generator));
    }

    std::vector<float> update = last + G + (-dt)*gradient(last);
    list.push_back(update);

}

void Trajectoire::simule(int N)
{
    for( int i=0;i<N;i++)
    {
        (*this).actualise();
    }
}
