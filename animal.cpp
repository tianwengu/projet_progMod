#include <vector>
#include <string>
#include <sstream>
#include <random>
#include"coord.hpp"
#include"animal.hpp"
using namespace std;

Animal::Animal(int identifiant, Espece espece, Coord coord):id(identifiant),e(espece),c(coord){
    if (espece == Espece::renard)
        nourriture = FoodInit;
    else
        nourriture = 999999;
}
  
Espece Animal::getEspece()const{
    return e;
}
Coord Animal::getCoord() const{
    return c;
}
void Animal::setCoord(Coord coord){
    c = coord;
}
int Animal::getId()const{
    return id;
}
int Animal::getNouriture()const{
    return nourriture;
}


void Animal::mange(){
    if (e == Espece::renard){
        nourriture += FoodLapin;
        if (nourriture > MaxFood)
            nourriture = MaxFood;
    }
}
void Animal::jeune(){
    if (e == Espece::renard)
        nourriture -= 1;
}

bool Animal::survie() const{
    return nourriture >= 0;
}



string Animal::toString() const{
    stringstream ss;
    ss << "Espece: ";
    if (e == Espece::renard)
        ss << "renard";
    else
        ss << "lapin";
    ss << " identifiant: ";
    ss << id;
    ss << " coordonnees: ";
    ss << c;
    return ss.str();
    
}
bool Animal::seReproduit()const{
    if(nourriture >= FoodReprod)
        if ((float)(rand()) / ((float)(RAND_MAX)) <= ProbBirthRenard)
            return true;
    return false;

}
bool Animal::seReproduit(int n)const{
    if (n >= MinFreeBirthLapin)
        if ((float)(rand()) / ((float)(RAND_MAX)) <= ProbBirthLapin)
            return true;
    return false;
}
