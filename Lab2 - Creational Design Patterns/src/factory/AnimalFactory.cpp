#include "AnimalFactory.h" 

IAnimal* AnimalFactory::createDog(const std::string& name, int age, const std::string& breed) {
    return new Dog(name, age, breed);
}

IAnimal* AnimalFactory::createCat(const std::string& name, int age) {
    return new Cat(name, age);
}
