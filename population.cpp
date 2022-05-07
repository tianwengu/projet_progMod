#include "population.hpp"
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
    bool exist = false;
    int id;
    do{
        id = rand()%50;
        for(int i = 0;i< animaux.size(); i++){
            if(animaux[i].getId() == id)
                exist = true;
        }
    }while(not exist);
    return id;
}
void Population::set(Animal a){
    animaux.push_back(a);
    for(int i = 0; i < caseLibre.size();i++){
        if(caseLibre[i]==a.getCoord()){
            caseLibre.erase(caseLibre.begin()+i);
            return;
        }
    }

}
        
void Population::supprime(int id){
    for(int i = 0; i < animaux.size();i++){
        if(animaux[i].getId()==id){
            caseLibre.push_back(animaux[i].getCoord());
            animaux.erase(animaux.begin()+i);
            return;
        }
    }
}
