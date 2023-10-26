#include "AnimalGroup.h"
#include <iostream>

AnimalGroup::AnimalGroup(const std::string& groupName) : groupName(groupName) {}

void AnimalGroup::addAnimal(IAnimal* animal) {
    animals.push_back(animal);
}

std::string AnimalGroup::getName() const {
    return groupName;
}

int AnimalGroup::getAge() const {
    int totalAge = 0;
    for (const auto& animal : animals) {
        totalAge += animal->getAge();
    }
    return animals.empty() ? 0 : totalAge / animals.size();
}

void AnimalGroup::display() const {
    std::cout << "\nGroup: " << groupName << ", Average Age: " << getAge() << std::endl;
    for (const auto& animal : animals) {
        animal->display();
    }
}

void AnimalGroup::makeSound() const {
    for (const auto& animal : animals) {
        animal->makeSound();
    }
}
