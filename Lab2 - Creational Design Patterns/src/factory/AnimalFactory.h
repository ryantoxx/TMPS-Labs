#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H

#include "../animals/IAnimal.h" 
#include "../animals/Dog.h"     
#include "../animals/Cat.h"    

class AnimalFactory {
public:
    static IAnimal* createDog(const std::string& name, int age, const std::string& breed);
    static IAnimal* createCat(const std::string& name, int age);
};

#endif 
