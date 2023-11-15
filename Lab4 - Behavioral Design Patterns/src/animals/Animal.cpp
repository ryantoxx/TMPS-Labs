#include "Animal.h"

Animal::Animal(std::string name, int age) : name(name), age(age) {}

std::string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

void Animal::display() const  {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

void Animal::makeSound() const {
    
}
