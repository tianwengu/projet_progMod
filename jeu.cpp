#include<iostream>
#include<array>
#include<cstdlib>
#include<stdexcept>
#include<algorithm>
#include<vector>

#include "systeme.hpp"
using namespace std;

void Jeu::ajouteAnimal(Espece e, Coord c){
    int id = p.reserve();
    g.setcase(id, c);
    Animal a(id, e, c);
    p.set(a);
}

Jeu::Jeu(){
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++){
        int k = rand()%100;
        if(k<7){
            ajouteAnimal(Espece::renard,Coord(i));
        }else if(k<27){
            ajouteAnimal(Espece::lapin,Coord(i));
        }
    }
}

bool Jeu::verifieGrille() const{
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++){
        if(not g.caseVide(Coord(i))){
            int id = g.getCase(Coord(i));
            if(p.get(id).getCoord()!=Coord(i))
                return false;
        }
    }
    return true;
}
vector<Coord> Jeu::voisinsVides(Coord c) const{
    vector<Coord> t;
    Ensemble e = c.voisins();
    while(e.cardinal() != 0){
        int k = e.tire();
        if(g.caseVide(Coord(k)))
            t.push_back(Coord(k));
    }
    return t;
}
        
vector<Coord> Jeu::voisinsEspece(Coord c,Espece e) const{
    vector<Coord> t;
    Ensemble voisin = c.voisins();
    while(voisin.cardinal() != 0){
        int k = voisin.tire();
        Animal a = p.get(g.getCase(Coord(k)));
        if(a.getEspece() == e)
            t.push_back(Coord(k));
    }
    return t;
}
        
void Jeu::deplace(Animal a){
    Coord c = a.getCoord();
    vector<Coord> t = voisinsVides(c);
    int k = rand()%t.size();
    g.setcase(a.getId(),Coord(t[k]));
}