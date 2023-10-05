#ifndef IADOPTION_CENTER_H
#define IADOPTION_CENTER_H

#include <string>
#include "../animals/IAnimal.h"

class IAdoptionCenter {
public:
    virtual std::string getName() const = 0;
    virtual void addAnimal(IAnimal* animal) = 0;
    virtual void displayAnimals() const = 0;
    virtual IAnimal* adoptAnimal(const std::string& animalName) = 0;
    // virtual ~IAdoptionCenter() {}
};

#endif 
