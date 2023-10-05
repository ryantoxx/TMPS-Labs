#include <iostream>
#include <string>
#include <vector>

// Interface for animals
class IAnimal {
public:
    virtual std::string getName() const = 0;
    virtual int getAge() const = 0;
    virtual void display() const = 0;
    virtual void makeSound() const = 0;
    virtual ~IAnimal() {} // A virtual destructor is necessary for the base interface class.
};

// Abstract base class for animals
class Animal : public IAnimal {
public:
    Animal(std::string name, int age) : name(name), age(age) {}

    std::string getName() const override {
        return name;
    }

    int getAge() const override {
        return age;
    }

    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    virtual void makeSound() const = 0;

private:
    std::string name;
    int age;
};

// Dog class as a specific animal implementation
class Dog : public Animal {
public:
    Dog(const std::string& name, int age, const std::string& breed)
        : Animal(name, age), breed(breed) {}

    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }

    void display() const override {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Breed: " << breed << std::endl;
    }

private:
    std::string breed;
};

class Cat : public Animal {
public:
    Cat(const std::string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

// Interface for Adoption Centers
class IAdoptionCenter {
public:
    virtual std::string getName() const = 0;
    virtual void addAnimal(IAnimal* animal) = 0;
    virtual void displayAnimals() const = 0;
    virtual IAnimal* adoptAnimal(const std::string& animalName) = 0;
    virtual ~IAdoptionCenter() {}
};

// AdoptionCenter class implementing IAdoptionCenter
class AdoptionCenter : public IAdoptionCenter {
public:
    AdoptionCenter(const std::string& name) : name(name) {}

    std::string getName() const override {
        return name;
    }

    void addAnimal(IAnimal* animal) override {
        animals.push_back(animal);
    }

    void displayAnimals() const override {
        std::cout << "Animals available at " << name << ":" << std::endl;
        for (const auto& animal : animals) {
            animal->display();
        }
    }

    IAnimal* adoptAnimal(const std::string& animalName) override {
        for (auto it = animals.begin(); it != animals.end(); ++it) {
            if ((*it)->getName() == animalName) {
                IAnimal* adoptedAnimal = *it;
                animals.erase(it);
                return adoptedAnimal;
            }
        }
        return 0;
    }

private:
    std::string name;
    std::vector<IAnimal*> animals;
};

// Adopter class
class Adopter {
public:
    Adopter(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

    void applyForAdoption(IAdoptionCenter* center, const std::string& animalName) {
        IAnimal* adoptedAnimal = center->adoptAnimal(animalName);
        if (adoptedAnimal != nullptr) {
            adoptedAnimals.push_back(adoptedAnimal);
            std::cout << name << " has adopted " << animalName << std::endl;
        } else {
            std::cout << name << " could not adopt " << animalName << std::endl;
        }
    }

    void displayApplications() const {
        std::cout << name << "'s adoption applications:" << std::endl;
        for (const auto& application : adoptedAnimals) {
            application->display();
        }
    }

private:
    std::string name;
    std::vector<IAnimal*> adoptedAnimals;
};


// Interface for Adoption Applications
class IAdoptionApplication {
public:
    virtual void display() const = 0;
    virtual ~IAdoptionApplication() {}
};

// AdoptionApplication class implementing IAdoptionApplication
class AdoptionApplication : public IAdoptionApplication {
public:
    AdoptionApplication(Adopter* adopter, const std::string& animalName)
        : adopter(adopter), animalName(animalName) {}

    void display() const override {
        std::cout << "Adopter: " << adopter->getName() << ", Animal: " << animalName << std::endl;
    }

private:
    Adopter* adopter;
    std::string animalName;
};

int main() {
    // Creating AdoptionCenter and animals
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

    // Display available animals
    center->displayAnimals();

    // John applies for adoption
    adopter1.applyForAdoption(center, "Buddy");
    adopter2.applyForAdoption(center, "Whiskers");

    IAdoptionApplication* application1 = new AdoptionApplication(&adopter1,"Buddy");
    adoptionApplications.push_back(application1);

    AdoptionApplication* application2 = new AdoptionApplication(&adopter2, "Whiskers");
    adoptionApplications.push_back(application2);

    std::cout << "Applications after Alice's request:" << std::endl;
    adopter2.displayApplications();

    std::cout << "\nAdoption Applications:" << std::endl;
    for (const auto& application : adoptionApplications) {
        application->display();
    }

    // Display available animals after adoptions
    center->displayAnimals();

    // Cleanup
    delete dog1;
    delete dog2;
    delete cat;
    delete center;
    delete application1;
    delete application2;

    return 0;
}








