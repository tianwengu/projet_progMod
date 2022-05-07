#include "jeu.hpp"
#include "grille.hpp"
#include "population.hpp"
#include <vector>

using namespace std;

void Jeu::ajouteAnimal(Espece e, Coord c){
    int id = p.reserve();
    Animal a = Animal(id,e,c);
    p.set(a);
    g.setcase(id,c);
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

Ensemble Jeu::voisinsVides(Coord c) const{
    Ensemble voisin;
    Ensemble e = c.voisins();
    while(e.cardinal() != 0){
        int k = e.tire();
        if(g.caseVide(Coord(k)))
            voisin.ajoute(k);
    }
    return voisin;
}

Ensemble Jeu::voisinsLapin(Coord c) const{
    Ensemble t;
    Ensemble voisin = c.voisins();
    while(voisin.cardinal() != 0){
        int k = voisin.tire();
        Animal a = p.get(g.getCase(Coord(k)));
        if(a.getEspece() == Espece::lapin)
            t.ajoute(k);
    }
    return t;
}

void Jeu::deplace(Animal a){
    Coord c = a.getCoord();
    Ensemble v = voisinsVides(c);
    if(a.getEspece() == Espece::lapin){
        int k = v.tire();//随机取一个坐标的整数值
        if (a.seReproduit() == true){
            ajouteAnimal(Espece::lapin, a.getCoord());//繁殖
        }
        g.setcase(a.getId(),Coord(k));//转移过去
    }
    if(a.getEspece() == Espece::renard){
        a.jeune();//减一食物
        if (not a.survie()){//饿死
            g.videCase(c);
            return;
        }
        Ensemble l = voisinsLapin(c);
        if (l.cardinal() != 0){
            int k = l.tire();
            g.videCase(Coord(k));
            a.mange();
            Coord c_origin = a.getCoord();
            g.setcase(a.getId(),Coord(k));
            if (a.seReproduit(a.getNouriture()) == true){
                ajouteAnimal(Espece::renard, c_origin);
            }

        }
        else{
            int k = v.tire();
            Coord c_origin = a.getCoord();
            g.setcase(a.getId(),Coord(k));
            if (a.seReproduit(a.getNouriture()) == true){
                ajouteAnimal(Espece::renard, c_origin);
            }
        }
    }
}
