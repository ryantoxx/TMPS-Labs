#include "AdoptionApplication.h"

AdoptionApplication::AdoptionApplication(Adopter* adopter, const std::string& animalName)
    : adopter(adopter), animalName(animalName) {}

void AdoptionApplication::display() const {
    std::cout << "Adopter: " << adopter->getName() << ", Animal: " << animalName << std::endl;
}
