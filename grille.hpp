#ifndef GRILLE_H
#define GRILLE_H

#include "coord.hpp"
#include <array>
class Grille{

    public:
        Grille();
        bool caseVide(Coord c) const;
        int getCase(Coord c) const;
        void videCase(Coord c);
        void setcase(int id, Coord c);
    private:
        array <int, 400> g;

};

#endif