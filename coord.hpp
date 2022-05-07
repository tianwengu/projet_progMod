#ifndef COORD_HPP
#define COORD_HPP
#include <array>
#include "ensemble.hpp"
using namespace std;
#define MAXCARD 100
#define TAILLEGRILLE 5

class Coord{
    public:
        Coord(int n);
        Coord(int l, int c);   
        int getX() const;
        int getY() const;
        friend bool operator==(Coord const & c1,Coord const & c2 );
        friend bool operator!=(Coord const & c1,Coord const & c2 );
        friend ostream& operator<<(ostream& out, Coord const &c);
        int toInt() const;
        Ensemble voisins() const;
    private:
        int x, y;
};

#endif
