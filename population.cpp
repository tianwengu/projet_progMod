#include<iostream>
#include<array>
#include<cstdlib>
#include<stdexcept>
#include<algorithm>
#include<vector>

#include "systeme.hpp"
using namespace std;

Population::Population(){
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE;i++){
        caseLibre.push_back(Coord(i));
    }
}

Animal Population::get(int id)const{
    for(int i = 0; i < animaux.size();i++){
        if(animaux[i].getId()==id)
            return animaux[i];
    }
    throw invalid_argument("Pas de animal avec cet id !");
}
     
     
vector<int> Population::getIds()const{ 
    vector<int> t;
    for(int i = 0; i < animaux.size();i++){
        t.push_back(animaux[i].getId());
    }
    return t;
}

int Population::reserve(){
    
}
void Population::set(Animal a){
    animaux.push_back(a);

}
        
void Population::supprime(int id){
    for(int i = 0; i < animaux.size();i++){
        if(animaux[i].getId()==id){
            for(int j = 0; j < caseLibre.size();j++){
                if(caseLibre[j] == animaux[i].getCoord())
                    caseLibre.erase(j);
            }
            animaux.erase(i);
        }
    }
    for(int i = 0; i < caseLibre.size();i++)
}