#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name, int age, const std::string& breed)
    : Animal(name, age), breed(breed) {}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::display() const {
    std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Breed: " << breed << std::endl;
}

