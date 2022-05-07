#ifndef JEU_HPP
#define JEU_HPP

#include "animal.hpp"
#include "grille.hpp"
struct Jeu{
    public:
        Jeu();
        void ajouteAnimal(Espece e, Coord c);
        bool verifieGrille() const;
        vector<Coord> voisinsVides(Coord c) const;
        vector<Coord> voisinsEspece(Coord c, Espece e) const;
        void deplace(Animal a);
    private:
        Grille g;
        Population p;
};
#endif