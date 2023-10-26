#include "AdoptionCenterProxy.h"
#include "../adoption/AdoptionCenter.h" 
#include <iostream>

AdoptionCenterProxy::AdoptionCenterProxy(const std::string& name, AccessLevel level) : realCenter(new AdoptionCenter(name)), accessLevel(level) {}

std::string AdoptionCenterProxy::getName() const {
    return realCenter->getName();
}

void AdoptionCenterProxy::addAnimal(IAnimal* animal) {
    realCenter->addAnimal(animal);
}

void AdoptionCenterProxy::displayAnimals() const {
    realCenter->displayAnimals();
}

IAnimal* AdoptionCenterProxy::adoptAnimal(const std::string& animalName) {
    if (accessLevel == ACCESS_ADOPTER) {
        return realCenter->adoptAnimal(animalName);
    } else {
        std::cout << "\nYou don't have access to adopt animals." << std::endl;
        return nullptr;
    }
}

AdoptionCenterProxy::~AdoptionCenterProxy() {
    delete realCenter;
}
