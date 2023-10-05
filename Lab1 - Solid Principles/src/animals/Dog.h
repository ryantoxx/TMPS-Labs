#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& breed);

    void makeSound() const override;
    void display() const override;

};

#endif 
