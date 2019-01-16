/**
 * @file
 * @author  Rabindra Khadka <rabindra.khadka@ymail.com>
 *          Tommaso Rodani <trodnai@sissa.it>
 *
 * @version 1.0
 *
 *
 * @section DESCRIPTION
 *
 * The .
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>

void printElements(auto& C)
{
    for (auto e:C)
    std::cout<<e<< " " << std::endl;

}

int main()
{
//Declaring a generalised lambda expression and store it in greater

auto greater=[](auto a, auto b)->bool{
    return a>b;
};

// initalise a vector
std::vector <double> vd ={4.5,7.8,3.44} ;
std::vector<std::string>vs ={"tom","brad","Angie", "Kubair"};

std::sort(vd.begin(),vd.end(),greater);
std::sort(vs.begin(),vs.end(),greater);

printElements(vd);
printElements(vs);

return 0;



}
