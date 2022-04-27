#include<iostream>
#include<array>
#include<cstdlib>
#include<stdexcept>
#include<algorithm>
#include "ensemble.hpp"
using namespace std;

int Ensemble::cardinal()const{
    return card;
}

bool Ensemble::estVide()const{
    return card == 0;
}

void Ensemble::ajoute(int a){
    if (card == MAXCARD)
        throw runtime_error("l'ensemble ayant déjà atteint la taille maximale");
    else
        t[card++] = a;
}

int Ensemble::tire(){
    if (estVide())
        throw runtime_error("l'ensemble est vide");
    else{
        int ind = rand() % card;
        int a = t[ind];
        t[ind] = t[card - 1];
        card--;
        return a;
    }
}

ostream& operator<<(ostream& out, Ensemble const &e){
    for(int i = 0; i < e.card; i++){
        out << e.t[i] << ", " ;       
    }
    out << endl;
    return out;
}
