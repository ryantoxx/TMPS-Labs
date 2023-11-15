#include "AdoptionCenter.h"

AdoptionCenter::AdoptionCenter(const std::string& name) : name(name), sortingStrategy(nullptr) {}

std::string AdoptionCenter::getName() const {
    return name;
}

void AdoptionCenter::addAnimal(IAnimal* animal)  {
    animals.push_back(animal);
}


void AdoptionCenter::displayAnimals() const {
    std::cout << "\nAnimals available at " << name << ":" << std::endl;
        for (const auto& animal : animals) {
            animal->display();
        }
}

IAnimal* AdoptionCenter::adoptAnimal(const std::string& animalName)  {
    for (auto i = animals.begin(); i != animals.end(); ++i) {
            if ((*i)->getName() == animalName) {
                IAnimal* adoptedAnimal = *i;
                animals.erase(i);
                return adoptedAnimal;
            }
        }
        return 0;
}

void AdoptionCenter::addObserver(IObserver* observer) {
    observers.push_back(observer);
}

void AdoptionCenter::notifyObservers(const std::string& message) const {
    for (const auto& observer : observers) {
        observer->update(message);
    }
}

void AdoptionCenter::setSortingStrategy(ISortingStrategy* strategy) {
    sortingStrategy = strategy;
}

void AdoptionCenter::performSort() {
    if (sortingStrategy != nullptr) {
        sortingStrategy->sort(animals);
    }
}

AdoptionCenter::~AdoptionCenter() {
    for (auto& animal : animals) {
        delete animal;
    }
    for (auto& observer : observers) {
        delete observer;
    }
}

