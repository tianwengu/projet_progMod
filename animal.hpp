#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include"coord.hpp"
using namespace std;
#define FoodInit 5
#define FoodLapin 5
#define FoodReprod 8
#define MaxFood 10
#define ProbBirthRenard 0.05
#define ProbBirthLapin 0.30
#define MinFreeBirthLapin 4


enum class Espece{lapin, renard};

class Animal{
    public:
        Animal(int identifiant, Espece espece, Coord coord);
        Espece getEspece()const;
        Coord getCoord() const;
        void setCoord(Coord coord);
        int getId()const;
        int getNouriture()const;
        void mange();
        void jeune();
        bool survie() const;
        string toString() const;
        bool seReproduit()const;
        bool seReproduit(int n)const;
    private:
        int id;
        Espece e;
        Coord c;
        int nourriture;

};

#endif