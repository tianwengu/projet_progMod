#ifndef JEU_HPP
#define JEU_HPP

#include "animal.hpp"
#include "grille.hpp"
#include "population.hpp"
struct Jeu
{
    Population p;
    Grille g;

    Jeu();
    void ajouteAnimal(Espece e, Coord c);
    bool verifieGrille() const;
    Ensemble voisinsVides(Coord c) const;
    Ensemble voisinsLapin(Coord c) const;
    void deplace(Animal a);
};

#endif