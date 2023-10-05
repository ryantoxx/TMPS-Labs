#ifndef ADOPTER_H
#define ADOPTER_H

#include <iostream>
#include <string>
#include <vector>
#include "../adoption/IAdoptionCenter.h"
#include "../animals/IAnimal.h"

class Adopter {
private:
    std::string name;
    std::vector<IAnimal*> adoptedAnimals;

public:
    Adopter(const std::string& name);
    std::string getName() const;
    void applyForAdoption(IAdoptionCenter* center, const std::string& animalName); 
};


#endif 

