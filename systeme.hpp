#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

enum class Espece{lapin, renard};

class Coord{
    public:
        Coord(int x, int y);   
        int getX() const;
        int getY() const;
        bool operator==(Coord c)const;
        bool operator!=(Coord c)const;
        vector<Coord> EnsCoord_voisins(Coord c) const;
    private:
        int x, y;
};

class Animal{
    public:
        Animal(int id, Espece espece, Coord coord);
        Espece getEspece()const;
        Coord getCoord() const;
        void setCoord();
        int getId()const;
        int getNouriture()const;
        void mange(int n);
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

class Population{
    public:
        Population();
        Animal get(int id)const;
        vector<int> getIds()const;
        int reserve();
        void set(Animal a);
        void supprime(int id);
    private:
        array<Animal, 50> animaux;
        vector<Coord> caseLibre;
};

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

struct Jeu{
    public:
        Jeu();
        void ajouteAnimal(Espece e, Coord c);
        bool verifieGrille() const;
        vector<Coord> voisinsVides() const;
        vector<Coord> voisinsEspece(Espece e) const;
        void deplace();
    private:
        Grille g;
        Population p;
};

void Jeu::ajouteAnimal(Espece e, Coord c){
    int id = p.reserve();
    g.setcase(id, c);
    Animal a(id, e, c);
    p.set(a);
}