#include<iostream>
#include<array>
#include<cstdlib>
#include<stdexcept>
#include<algorithm>
#include "systeme.hpp"
using namespace std;

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
        void set(Animal a);
        void supprime(int id);