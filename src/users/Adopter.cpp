#include "Adopter.h"
#include "iostream"

Adopter::Adopter(const std::string& name) : name(name) {}

std::string Adopter::getName() const {
    return name;
}

void Adopter::applyForAdoption(IAdoptionCenter* center, const std::string& animalName) {
    IAnimal* adoptedAnimal = center->adoptAnimal(animalName);
        if (adoptedAnimal != nullptr) {
            adoptedAnimals.push_back(adoptedAnimal);
            std::cout << "\n" << name << " has adopted " << animalName << std::endl;
        } else {
            std::cout << "\n" << name << " could not adopt " << animalName << std::endl;
        }
}

void Adopter::displayApplications() const {
    std::cout << "\n" << name << "'s adoption applications:" << std::endl;
        for (const auto& application : adoptedAnimals) {
            application->display();
        }
}

