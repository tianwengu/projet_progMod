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
     
     
        vector<int> getIds()const;
        int reserve();
        void set(Animal a);
        void supprime(int id);