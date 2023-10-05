#include "AdoptionCenter.h"

AdoptionCenter::AdoptionCenter(const std::string& name) : name(name) {}

std::string AdoptionCenter::getName() const {
    return name;
}

void AdoptionCenter::addAnimal(IAnimal* animal)  {
    animals.push_back(animal);
}

void AdoptionCenter::displayAnimals() const {
    std::cout << "\n" << "Animals available at " << name << ":" << std::endl;
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

