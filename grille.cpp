#include<array>
#include "grille.hpp"
using namespace std;
#define Vide -1

Grille::Grille(){
    for(int i = 0; i < 400; i++)
        g[i] = Vide;
}

bool Grille::caseVide(Coord c) const{
    return g[c.toInt()] == Vide;
}

int Grille::getCase(Coord c) const{
    return g[c.toInt()];
}

void Grille::videCase(Coord c){
    g[c.toInt()] = Vide;
}

void Grille::setcase(int id, Coord c){
    g[c.toInt()] = id;
}