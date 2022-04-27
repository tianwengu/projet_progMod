#ifndef ENSEMBLE_HPP
#define ENSEMBLE_HPP

#include <iostream>
#include <array>
using namespace std;
#define MAXCARD 100
class Ensemble{
    public:
        Ensemble(){card = 0;}
        friend ostream& operator<<(ostream& out, Ensemble const &e);
        bool estVide() const;
        int cardinal() const;
        void ajoute(int a);
        int tire();
    private:
        int card;
        array<int, MAXCARD> t;
};

#endif