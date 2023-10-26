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

#include "adapter/AnimalAdoptionApplication.h"

#include "decorator/AdoptionApplicationDecorator.h"

#include "composite/AnimalGroup.h"

#include "proxy/AdoptionCenterProxy.h"


int main() {
    
    std::vector<IAdoptionApplication*> adoptionApplications;
    // <----> Proxy Design Pattern
    IAdoptionCenter* visitorCenter = new AdoptionCenterProxy("Pet Adoption Center", ACCESS_VISITOR);
    IAdoptionCenter* adopterCenter = new AdoptionCenterProxy("Pet Adoption Center", ACCESS_ADOPTER);

    IAnimal* dog1 = new Dog("Buddy", 3, "Golden Retriever");
    IAnimal* cat = new Cat("Whiskers", 2);
    IAnimal* dog2 = new Dog("Tuzik", 1, "Bulldog");

    // <----> Composite Design Pattern
    IAnimal* animalGroup = new AnimalGroup("Pets Group");
    static_cast<AnimalGroup*>(animalGroup)->addAnimal(dog1);
    static_cast<AnimalGroup*>(animalGroup)->addAnimal(cat);
    static_cast<AnimalGroup*>(animalGroup)->addAnimal(dog2);


    adopterCenter->addAnimal(dog1);
    adopterCenter->addAnimal(cat);
    adopterCenter->addAnimal(dog2);

    std::cout << "\n" << "Animals available at " << adopterCenter->getName() << ":" << std::endl;
    std::vector<IAnimal*> animals = {dog1, cat, dog2, animalGroup};

    dog1->display();
    dog2->display();
    cat->display();
    animalGroup->display();
    
    Adopter adopter1("John");
    Adopter adopter2("Alice");

    adopter1.applyForAdoption(adopterCenter, "Buddy");
    // adopter2.applyForAdoption(adopterCenter, "Whiskers");
    adopter2.applyForAdoption(visitorCenter, "Whiskers");

    // <----> Adapter Design Pattern
    IAdoptionApplication* application1 = new AnimalAdoptionApplication(&adopter1, dog1);
    adoptionApplications.push_back(application1);

    IAdoptionApplication* application2 = new AnimalAdoptionApplication(&adopter2, cat);
    adoptionApplications.push_back(application2);

    std::cout << "\n" << "Applications at the " << adopterCenter->getName() << ":" << std::endl;
    std::vector<IAdoptionApplication*> availableApplications = {application1, application2};
    for (const auto& application : adoptionApplications) {
        application->display();
    }

    // <----> Decorator Design Pattern
    IAdoptionApplication* decoratedApplication1 = new AdoptionApplication(&adopter1, "Buddy");
    decoratedApplication1 = new AdoptionApplicationDecorator(decoratedApplication1, "Loves playing with a ball");
    adoptionApplications.push_back(decoratedApplication1);

    IAdoptionApplication* decoratedApplication2 = new AdoptionApplication(&adopter2, "Whiskers");
    decoratedApplication2 = new AdoptionApplicationDecorator(decoratedApplication2, "Enjoys sunbathing");
    adoptionApplications.push_back(decoratedApplication2);

    std::cout << "\nDecorated Applications at the " << adopterCenter->getName() << ":" << std::endl;
    decoratedApplication1->display();
    decoratedApplication2->display();

    std::cout << "\n" << "Remaining animals at the " << adopterCenter->getName() << ":" << std::endl;
    adopterCenter->displayAnimals();
    
    delete dog1;
    delete dog2;
    delete cat;
    delete animalGroup;
    delete adopterCenter;
    delete visitorCenter;
    delete decoratedApplication1;
    delete decoratedApplication2;
    delete application1;
    delete application2;

    return 0;
}





















