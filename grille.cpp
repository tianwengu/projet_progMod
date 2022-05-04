#include<iostream>
#include<vector>
#include "systeme.hpp"
using namespace std;

Grille::Grille(){
    p = Population();
}

bool Grille::caseVide(Coord c) const{
    vector<int> t = p.getIds();
    for(int i = 0; i < t.size();i++){
        if(c == p.get(t[i]).getCoord())
            return false;
    }
    return true;
}
        
int Grille::getCase(Coord c) const{
    vector<int> t = p.getIds();
    for(int i = 0; i < t.size();i++){
        if(c == p.get(t[i]).getCoord())
            return t[i];
    }
}

void Grille::videCase(Coord c){
    int id = getCase(c);
    p.supprime(id); 
}

void Grille::setcase(int id, Coord c){
    vector<int> t = p.getIds();
    for(int i = 0; i < t.size();i++){
        if(id == t[i]){
            Animal a = p.get(t[i]);
            p.supprime(id);
            a.setCoord(c);
            p.reserve(id);
            p.set(a);
            return;
        }   
    }
}