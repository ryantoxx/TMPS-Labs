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
        } else {
            std::cout << "\n" << name << " could not adopt " << animalName << std::endl;
        }
}

void Adopter::displayApplications() const {
    std::cout << name << "'s adoption applications:" << std::endl;
    for (const auto& application : adoptedAnimals) {
        application->display();
    }
}

void Adopter::setCommand(ICommand* command) {
    adoptionCommand = command;
}

void Adopter::executeAdoptionCommand() {
    if (adoptionCommand != nullptr) {
        adoptionCommand->execute();
        adoptionCommand = nullptr;
    }
}


