#include<iostream>
#include"coord.hpp"
#include"ensemble.hpp"
#include"animal.hpp"
#include"population.hpp"
#include"grille.hpp"
#include"jeu.hpp"

#define RESET   "\033[0m"
#define WOLF    "\033[41m"  
#define RABBIT  "\033[42m"
#define VIDE    "\033[107m"
using namespace std;

void affiche(Grille g){
    for(int i = 0; i < TAILLEGRILLE;i++){
        for(int j = 0; j < TAILLEGRILLE;j++){
            if(g.caseVide(Coord(i*TAILLEGRILLE +j))){
                cout<<VIDE<<" ";
            }else{
                int id = g.getCase(Coord(i*TAILLEGRILLE +j));
                Animal a = 
            }
            
        }
    }
}
int main(){
   
}