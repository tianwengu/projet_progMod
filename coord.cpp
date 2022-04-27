#include<iostream>
#include<array>
#include<cstdlib>
#include<stdexcept>
#include<algorithm>
#include "coord.hpp"
using namespace std;
Coord::Coord(int l, int c){
    if (l < 0 or c < 0 or l > TAILLEGRILLE-1 or c > TAILLEGRILLE-1){
        throw invalid_argument("coordonnée en dehors de la grille !");
    }
    x = l;
    y = c;
}

Coord::Coord(int n){
    if (n < 0 or n > TAILLEGRILLE*TAILLEGRILLE - 1){
        throw invalid_argument("coordonnée en dehors de la grille !");
    }
    x = n % TAILLEGRILLE;
    y = n - (x * TAILLEGRILLE);
}

int Coord::getX() const{
    return x;
}


int Coord::getY() const{
    return y;
}

bool operator==(Coord const &c1, Coord const &c2){
    return c1.x == c2.x and c1.y == c2.y;
}       

bool operator!=(Coord const &c1, Coord const &c2){
    return c1.x != c2.x and c1.y != c2.y;
}

ostream& operator<<(ostream& out, Coord const &c) {
    out<<"("<<c.x<<", "<<c.y<<")";
    return out;
}

int Coord::toInt()const{
    return x * TAILLEGRILLE + y;
}

Ensemble Coord::voisins()const{
    Ensemble voisin;
    for(int i = max(x - 1, 0); i <= min(x + 1, TAILLEGRILLE - 1); i++){
        for(int j = max(y - 1, 0); j <= min(y + 1, TAILLEGRILLE - 1); j++){
            if(i != x or j != y){
                Coord c{i, j};
                voisin.ajoute(c.toInt());
            }
        }
    }
    return voisin;
}
