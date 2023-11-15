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
#include "observer/AdopterObserver.h"
#include "command/AddAnimalCommand.h"
#include "strategy/SortByAge.h"
#include "strategy/SortByName.h"

int main() {
    std::vector<IAdoptionApplication*> adoptionApplications;
    IAdoptionCenter* center = new AdoptionCenter("Pet Adoption Center");
    IAnimal* dog1 = new Dog("Buddy", 3, "Golden Retriever");
    IAnimal* cat = new Cat("Whiskers", 2);
    IAnimal* dog2 = new Dog("Tuzik", 1, "Bulldog");

    center->addAnimal(dog1);
    center->addAnimal(cat);
    center->addAnimal(dog2);

    Adopter adopter1("John");
    Adopter adopter2("Alice");
    Adopter adopter3("Bob");

    // ==> Observer Design Pattern <==
    IObserver* johnObserver = new AdopterObserver("John");
    IObserver* aliceObserver = new AdopterObserver("Alice");
    IObserver* bobObserver = new AdopterObserver("Bob");

    center->addObserver(johnObserver);
    center->addObserver(aliceObserver);
    center->addObserver(bobObserver);

    center->displayAnimals();

    // ==> Command Design Pattern <==
    ICommand* command1 = new AddAnimalCommand(center, new Dog("Jack", 3, "Labrador"));
    ICommand* command2 = new AddAnimalCommand(center, new Cat("Bella", 2));

    adopter1.setCommand(command1);
    adopter2.setCommand(command2);

    adopter1.executeAdoptionCommand();
    adopter2.executeAdoptionCommand();

    IAdoptionApplication* application1 = new AdoptionApplication(&adopter1, "Buddy");
    adoptionApplications.push_back(application1);

    AdoptionApplication* application2 = new AdoptionApplication(&adopter2, "Whiskers");
    adoptionApplications.push_back(application2);

    AdoptionApplication* application3 = new AdoptionApplication(&adopter3, "Tuzik");
    adoptionApplications.push_back(application3);

    std::cout << "\nAdoption Applications:" << std::endl;
    for (const auto& application : adoptionApplications) {
        application->display();
    }

    // ==> Strategy Design Pattern <==
    ISortingStrategy* sortByAgeStrategy = new SortByAge();
    ISortingStrategy* sortByNameStrategy = new SortByName();

    center->setSortingStrategy(sortByAgeStrategy);

    std::cout << "\nAnimals before sorting:" << std::endl;
    center->displayAnimals();

    // Perform sorting by age
    center->performSort();
    std::cout << "\nAnimals after sorting by age:" << std::endl;
    center->displayAnimals();

    center->setSortingStrategy(sortByNameStrategy);

    // Perform sorting by name
    center->performSort();
    std::cout << "\nAnimals after sorting by name:" << std::endl;
    center->displayAnimals();

    IAnimal* newAnimal1 = new Dog("Max", 2, "Labrador");
    IAnimal* newAnimal2 = new Cat("Mittens", 3);
    center->addAnimal(newAnimal1);
    center->addAnimal(newAnimal2);

    center->notifyObservers("Two new animals, Max and Mittens, have been added!");

    delete dog1;
    delete dog2;
    delete cat;
    delete newAnimal1;
    delete newAnimal2;
    delete center;
    delete application1;
    delete application2;
    delete application3;
    delete johnObserver;
    delete aliceObserver;
    delete bobObserver;
    delete command1;
    delete command2;

    return 0;
}
