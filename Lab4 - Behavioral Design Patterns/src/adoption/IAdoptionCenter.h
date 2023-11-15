#ifndef IADOPTION_CENTER_H
#define IADOPTION_CENTER_H

#include <string>
#include "../animals/IAnimal.h"
#include "../observer/IObserver.h"
#include "../strategy/ISortingStrategy.h"

class IAdoptionCenter {
public:
    virtual std::string getName() const = 0;
    virtual void addAnimal(IAnimal* animal) = 0;
    virtual void addObserver(IObserver* observer) = 0;
    virtual void notifyObservers(const std::string& message) const = 0;
    virtual void displayAnimals() const = 0;
    virtual IAnimal* adoptAnimal(const std::string& animalName) = 0;
    virtual void setSortingStrategy(ISortingStrategy* strategy) = 0;
    virtual void performSort() = 0;
    virtual ~IAdoptionCenter() {}
};


#endif 
