#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    Cat(const std::string& name, int age);

    void makeSound() const override;
};

#endif 

