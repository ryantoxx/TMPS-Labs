# Topic: Structural Design Patterns
## Course: Software Design Techniques and Mechanisms
## Author: Chihai Nichita

---

## Theory:
Structural design patterns are a category of design patterns that focus on the composition of classes and objects to form larger structures and systems. They provide a way to organize objects and classes in a way that is both flexible and efficient, while allowing for the reuse and modification of existing code. Structural design patterns address common problems encountered in the composition of classes and objects, such as how to create new objects that inherit functionality from existing objects, how to create objects that share functionality without duplicating code, or how to define relationships between objects in a flexible and extensible way.

Some examples from this category of design patterns are:
* Adapter
* Bridge
* Composite
* Decorator
* Facade
* Flyweight
* Proxy

## Objectives:

1. Study and understand the Structural Design Patterns.

2. As a continuation of the previous laboratory work, think about the functionalities that your system will need to provide to the user.

3. Implement some additional functionalities, or create a new project using structural design patterns.

## Tasks:

1. By creating a new project, or extending your last one (Lab work Nr2), implement at least 2 structural design patterns in your project:

    The implemented design pattern should help to perform the tasks involved in your system.
    The object creation mechanisms/patterns can now be buried into the functionalities instead of using them into the client.
    There should only be one client for the whole system.

2. Keep your files grouped (into packages/directories) by their responsibilities (an example project structure):

3. Document your work in a separate markdown file according to the requirements presented below (the structure can be extended of course):

* Topic of the laboratory work
* Author
* Introduction/Theory/Motivation
* Implementation & Explanation (you can include code snippets as well)
* Indicate the location of the code snippet
* Emphasize the main idea and motivate the usage of the pattern
* Results/Screenshots/Conclusions

## Implementation:

### Adapter Design Pattern

The **AnimalAdoptionApplication** class acts as an adapter that follows the IAnimal object to be used as an IAdoptionApplication object.Using this approach I can create adoption applications and display them even if they involve animals.

```cpp
class AnimalAdoptionApplication : public IAdoptionApplication {
private:
    Adopter* adopter;
    IAnimal* animal;
public:
    AnimalAdoptionApplication(Adopter* adopter, IAnimal* animal) : adopter(adopter), animal(animal) {}

    void display() const override {
        std::cout << "Adopter: " << adopter->getName() << ", Animal: " << animal->getName() << std::endl;
    }
};

```

### Decorator Design Pattern 

The **AdoptionApplicationDecorator** class allows me to decorate my existing IAdoptionApplication objects with an additional piece of information without modifying those objects directly. This approach provides me a flexible way to extend the behaviour of objects at runtime. 

```cpp
class AdoptionApplicationDecorator : public IAdoptionApplication {
private:
    IAdoptionApplication* application;
    std::string message;
public:
    AdoptionApplicationDecorator(IAdoptionApplication* application, const std::string& message)
        : application(application), message(message) {}

    void display() const override {
        application->display();  // original application method
        std::cout << "Additional Message: " << message << std::endl;
    }

};
```

### Composite Design Pattern

The **AnimalGroup** class allows me to create a hierarchial structure of animlas, where this group can contain individuals animals (Dogs and Cats). This approach helps me to work with complex structures of objects in an uniform way. 

```cpp
class AnimalGroup : public IAnimal {
private:
    std::string groupName;
    std::vector<IAnimal*> animals;
public:
    AnimalGroup(const std::string& groupName) : groupName(groupName) {}

    void addAnimal(IAnimal* animal) {
        animals.push_back(animal);
    }

    std::string getName() const override {
        return groupName;
    }

    int getAge() const override {
        int totalAge = 0;
        for (const auto& animal : animals) {
            totalAge += animal->getAge();
        }
        return animals.empty() ? 0 : totalAge / animals.size();
    }

    void display() const override {
        std::cout << "Group: " << groupName << ", Average Age: " << getAge() << std::endl;
    }

    void makeSound() const override {
        for (const auto& animal : animals) {
            animal->makeSound();
        }
    }
};
```

### Proxy Design Pattern 

The **AdoptionCenterProxy** class allows me to control access to the AdoptionCenter object based on the access level. This approach helps me introducing an intermediary object that manages access to the base object. 

```cpp
enum AccessLevel {
    ACCESS_VISITOR,
    ACCESS_ADOPTER
};

class AdoptionCenterProxy : public IAdoptionCenter {
public:
    AdoptionCenterProxy(const std::string& name, AccessLevel level) : realCenter(new AdoptionCenter(name)), accessLevel(level) {}

    std::string getName() const override {
        return realCenter->getName();
    }

    void addAnimal(IAnimal* animal) override {
        realCenter->addAnimal(animal);
    }

    void displayAnimals() const override {
        realCenter->displayAnimals();
    }

    IAnimal* adoptAnimal(const std::string& animalName) override {
        if (accessLevel == ACCESS_ADOPTER) {
            // Allow adopters to adopt animals without any restrictions
            return realCenter->adoptAnimal(animalName);
        } else {
            std::cout << "Permission denied. You don't have access to adopt animals." << std::endl;
            return nullptr;
        }
    }

    ~AdoptionCenterProxy() {
        delete realCenter;
    }

private:
    AdoptionCenter* realCenter;
    AccessLevel accessLevel;
};

```

## Results:

* Adapter 
```cpp
IAdoptionApplication* application1 = new AnimalAdoptionApplication(&adopter1, dog1);
adoptionApplications.push_back(application1);

IAdoptionApplication* application2 = new AnimalAdoptionApplication(&adopter2, cat);
adoptionApplications.push_back(application2);
```

* Decorator
```cpp
IAdoptionApplication* decoratedApplication1 = new AdoptionApplication(&adopter1, "Buddy");
    decoratedApplication1 = new AdoptionApplicationDecorator(decoratedApplication1, "Loves playing with a ball");
    adoptionApplications.push_back(decoratedApplication1);

    IAdoptionApplication* decoratedApplication2 = new AdoptionApplication(&adopter2, "Whiskers");
    decoratedApplication2 = new AdoptionApplicationDecorator(decoratedApplication2, "Enjoys sunbathing");
    adoptionApplications.push_back(decoratedApplication2);
```

* Composite
```cpp
IAnimal* animalGroup = new AnimalGroup("Pets Group");
    static_cast<AnimalGroup*>(animalGroup)->addAnimal(dog1);
    static_cast<AnimalGroup*>(animalGroup)->addAnimal(cat);
    static_cast<AnimalGroup*>(animalGroup)->addAnimal(dog2);
```
  
* Proxy
```cpp
IAdoptionCenter* visitorCenter = new AdoptionCenterProxy("Pet Adoption Center", ACCESS_VISITOR);
IAdoptionCenter* adopterCenter = new AdoptionCenterProxy("Pet Adoption Center", ACCESS_ADOPTER);
```

## Conclusion:

In conclusion I was able to implement four design patterns, Adapter, Decorator, Composite, Proxy. Implementing these pattern they allowed me create more efficient code, also using these patterns it has become easier to extend my code.

To sum up, studying these patterns has helped me build more efficient and readable code.
