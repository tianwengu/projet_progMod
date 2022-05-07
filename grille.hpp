#ifndef GRILLE_H
#define GRILLR_H

#include "coord.hpp"
#include "population.hpp"
class Grille{
    public:
        Grille();
        bool caseVide(Coord c) const;
        int getCase(Coord c) const;
        void videCase(Coord c);
        void setcase(int id, Coord c);
    private:
        Population p;

};

#endif