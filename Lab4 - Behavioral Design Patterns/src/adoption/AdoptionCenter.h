#ifndef ADOPTION_CENTER_H
#define ADOPTION_CENTER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "../animals/IAnimal.h"
#include "IAdoptionCenter.h"
#include "../observer/IObserver.h"
#include "../strategy/ISortingStrategy.h"

class AdoptionCenter : public IAdoptionCenter {
private:
    std::string name;
    std::vector<IAnimal*> animals;
    std::vector<IObserver*> observers;
    ISortingStrategy* sortingStrategy;
public:
    AdoptionCenter(const std::string& name);
    std::string getName() const override;
    void addAnimal(IAnimal* animal);
    void displayAnimals() const;
    IAnimal* adoptAnimal(const std::string& animalName);
    void addObserver(IObserver* observer) override;
    void notifyObservers(const std::string& message) const override;
    void setSortingStrategy(ISortingStrategy* strategy) override;
    void performSort() override;
    ~AdoptionCenter() override;

};

#endif 
