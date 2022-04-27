#include<iostream>
#include"coord.hpp"
#include"ensemble.hpp"
using namespace std;
int main(){
    Coord c{3, 4};
    Ensemble e{};
    e.ajoute(33);
    cout << c.toInt() << endl;
    cout << e ;
    cout << c.voisins();
    return 0;
}