#ifndef IANIMAL_H
#define IANIMAL_H

#include <string>

class IAnimal {
public:
    virtual std::string getName() const = 0;
    virtual int getAge() const = 0;
    virtual void display() const = 0;
    virtual void makeSound() const = 0;
    virtual ~IAnimal() {}
};

#endif 
