#include "AnimalAdoptionApplication.h"
#include <iostream>

AnimalAdoptionApplication::AnimalAdoptionApplication(Adopter* adopter, IAnimal* animal) : adopter(adopter), animal(animal) {}

void AnimalAdoptionApplication::display() const {
    std::cout << "Adopter: " << adopter->getName() << ", Animal: " << animal->getName() << std::endl;
}
