#include <iostream>
#include <vector>

#include "animals/Animal.h"
#include "animals/IAnimal.h"

#include "adoption/AdoptionApplication.h"
#include "adoption/AdoptionCenter.h"
#include "adoption/IAdoptionApplication.h"
#include "adoption/IAdoptionCenter.h"

#include "users/Adopter.h"

#include "factory/AnimalFactory.h"

#include "builder/AdoptionApplicationBuilder.h"
#include "builder/AdoptionApplicationDirector.h"
#include "builder/IAdoptionApplicationBuilder.h"

#include "singleton/AdoptionCenterSingleton.h"



int main() {
    
    std::vector<IAdoptionApplication*> adoptionApplications;
    IAdoptionCenter* center = AdoptionCenterSingleton::getInstance();
    IAdoptionCenter* center1 = AdoptionCenterSingleton::getInstance();

    // if (center == center1) {
    //     std::cout << "\nOnly one instance of AdoptionCenter is created." << std::endl;
    // } else {
    //     std::cout << "\nMultiple instances of AdoptionCenter were created (not expected)." << std::endl;
    // }

    IAnimal* dog1 = AnimalFactory::createDog("Buddy", 3, "Golden Retriever");
    IAnimal* cat = AnimalFactory::createCat("Whiskers", 2);
    IAnimal* dog2 = AnimalFactory::createDog("Tuzic", 5, "Bulldog");
    IAnimal* cat2 = AnimalFactory::createCat("Puffy", 5);
   
    center->addAnimal(dog1);
    center->addAnimal(cat);
    center->addAnimal(dog2);
    center->addAnimal(cat2);

    std::cout << "\nAnimals available at " << center->getName() << ":" << std::endl;
    dog1->display();
    dog1->makeSound();
    cat->display();
    cat->makeSound();
    dog2->display();
    dog2->makeSound();
    cat2->display();
    cat2->makeSound();

    Adopter adopter1("John");
    Adopter adopter2("Alice");
    Adopter adopter3("James");

    adopter1.applyForAdoption(center, "Puffy");
    adopter2.applyForAdoption(center, "Whiskers");
    adopter3.applyForAdoption(center, "Buddy");
    

    AdoptionApplicationBuilder builder;

    AdoptionApplicationDirector director(&builder);

    IAdoptionApplication* application1 = director.buildDefaultApplication(&adopter3, "Buddy");
    IAdoptionApplication* application2 = director.buildApprovedApplication(&adopter2, "Whiskers", "2023-10-05");
    IAdoptionApplication* application3 = director.buildDeniedApplication(&adopter1, "Puffy", "2023-10-06");

    adoptionApplications.push_back(application1);
    adoptionApplications.push_back(application2);
    adoptionApplications.push_back(application3);

    std::cout << "\nAdoption Applications:" << std::endl;
    for (const auto& application : adoptionApplications) {
        application->displayApplications();
    }

    center->displayAnimals();

    delete dog1;
    delete dog2;
    delete cat;
    delete cat2;
    delete center;
    delete application1;
    delete application2;
    delete application3;

    return 0;
}








