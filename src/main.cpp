#include <iostream>

#include "animals/Animal.h"
#include "animals/Cat.h"
#include "animals/Dog.h"
#include "animals/IAnimal.h"

#include "adoption/AdoptionApplication.h"
#include "adoption/AdoptionCenter.h"
#include "adoption/IAdoptionApplication.h"
#include "adoption/IAdoptionCenter.h"

#include "users/Adopter.h"

int main() {

    IAdoptionCenter* center = new AdoptionCenter("Pet Adoption Center");
    IAnimal* dog1 = new Dog("Bobic", 3, "Golden Retriever");
    IAnimal* cat = new Cat("Barsik", 2); 
    IAnimal* dog2 = new Dog("Tuzik", 1, "Bulldog");

    center->addAnimal(dog1);
    center->addAnimal(cat);
    center->addAnimal(dog2);


    Adopter adopter1("Nicolae");
    Adopter adopter2("Viorica");
  
    //center->displayAnimals();
    std::cout << "\n" << "Animals available at " << center->getName() << ":" << std::endl;
    dog1->display();
    dog1->makeSound();
    cat->display();
    cat->makeSound();
    dog2->display();
    dog2->makeSound();

    adopter1.applyForAdoption(center, "Bobic");
    adopter1.displayApplications();

    adopter2.applyForAdoption(center, "Barsik");
    adopter2.displayApplications();

    center->displayAnimals();

    delete dog1;
    delete cat;
    delete center;
    delete dog2;

    return 0;
}








