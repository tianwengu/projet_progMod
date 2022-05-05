#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

enum class Espece{lapin, renard};
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


class Animal{
    public:
        Animal(int id, Espece espece, Coord coord);
        Espece getEspece()const;
        Coord getCoord() const;
        void setCoord(Coord c);
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
        vector<Animal> animaux;
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
        vector<Coord> voisinsVides(Coord c) const;
        vector<Coord> voisinsEspece(Coord c, Espece e) const;
        void deplace(Animal a);
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