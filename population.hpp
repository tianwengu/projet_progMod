#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "animal.hpp"
#include <vector>
using namespace std;

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
};

#endif