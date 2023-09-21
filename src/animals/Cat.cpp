#include "Cat.h"
#include <iostream>

Cat::Cat(const std::string& name, int age) : Animal(name, age) {}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
