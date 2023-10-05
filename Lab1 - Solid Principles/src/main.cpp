#include <iostream>
#include <vector>

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
    
    std::vector<IAdoptionApplication*> adoptionApplications;
    IAdoptionCenter* center = new AdoptionCenter("Pet Adoption Center");
    IAnimal* dog1 = new Dog("Buddy", 3, "Golden Retriever");
    IAnimal* cat = new Cat("Whiskers", 2);
    IAnimal* dog2 = new Dog("Tuzik", 1, "Bulldog");

    center->addAnimal(dog1);
    center->addAnimal(cat);
    center->addAnimal(dog2);

    std::cout << "\n" << "Animals available at " << center->getName() << ":" << std::endl;
    dog1->display();
    dog1->makeSound();
    cat->display();
    cat->makeSound();
    dog2->display();
    dog2->makeSound();

    // Creating Adopters
    Adopter adopter1("John");
    Adopter adopter2("Alice");

    adopter1.applyForAdoption(center, "Buddy");
    adopter2.applyForAdoption(center, "Whiskers");

    IAdoptionApplication* application1 = new AdoptionApplication(&adopter1,"Buddy");
    IAdoptionApplication* application2 = new AdoptionApplication(&adopter2, "Whiskers");

    adoptionApplications.push_back(application1);
    adoptionApplications.push_back(application2);

    std::cout << "\nAdoption Applications:" << std::endl;
    for (const auto& application : adoptionApplications) {
        application->displayApplications();
    }

    center->displayAnimals();

    delete dog1;
    delete dog2;
    delete cat;
    delete center;
    delete application1;
    delete application2;

    return 0;
}








