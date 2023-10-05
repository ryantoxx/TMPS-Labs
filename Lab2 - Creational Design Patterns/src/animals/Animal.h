#ifndef ANIMAL_H
#define ANIMAL_H

#include "iostream"
#include <string>
#include "IAnimal.h"


class Animal : public IAnimal {
private:
    std::string name;
    int age;

public:
    Animal(std::string, int age);

    std::string getName() const;
    int getAge() const;
    virtual void display() const;
    virtual void makeSound() const = 0;
};
#endif

