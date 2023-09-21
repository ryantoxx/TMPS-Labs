#ifndef ADOPTION_CENTER_H
#define ADOPTION_CENTER_H

#include <iostream>
#include <string>
#include <vector>
#include "../animals/IAnimal.h"
#include "IAdoptionCenter.h"

class AdoptionCenter : public IAdoptionCenter {
private:
    std::string name;
    std::vector<IAnimal*> animals;
public:
    AdoptionCenter(const std::string& name);
    std::string getName() const;
    void addAnimal(IAnimal* animal);
    void displayAnimals() const;
    IAnimal* adoptAnimal(const std::string& animalName);



};

#endif 
