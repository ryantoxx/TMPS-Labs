# Topic: Creational Design Patterns
## Course: Software Design Techniques and Mechanisms
## Author: Chihai Nichita

---

## Theory:
**Creational design patterns are concerned with the way of creating objects. These design patterns are used when a decision must be made at the time of instantiation of a class (i.e. creating an object of a class)**

### Factory Pattern
A Factory Pattern says that just define an interface or abstract class for creating an object but let the subclasses decide which class to instantiate. In other words, subclasses are responsible to create the instance of the class.

### Singleton Pattern
Singleton Pattern says that just"define a class that has only one instance and provides a global point of access to it".

In other words, a class must ensure that only single instance should be created and single object can be used by all other classes.

### Builder Pattern

Builder Pattern says that "construct a complex object from simple objects using step-by-step approach"

It is mostly used when object can't be created in single step like in the de-serialization of a complex object.

## Objectives:

Creational design patterns are a category of design patterns that focus on the process of object creation. They provide a way to create objects in a flexible and controlled manner, while decoupling the client code from the specifics of object creation. Creational design patterns address common problems encountered in object creation, such as how to create objects with different initialization parameters, how to create objects based on certain conditions, or how to ensure that only a single instance of an object is created. There are several creational design patterns that have their own strengths and weaknesses. Each of it is best suited for solving specific problems related to object creation. By using creational design patterns, developers can improve the flexibility, maintainability, and scalability of their code.

Some examples of this kind of design patterns are:

* Singleton

* Builder

* Prototype

* Object Pooling

* Factory Method

* Abstract Factory

## Tasks:

    1.Choose an OO programming language and a suitable IDE or Editor (No frameworks/libs/engines allowed).

    2. Select a domain area for the sample project.

    3. Define the main involved classes and think about what instantiation mechanisms are needed.

    4. Based on the previous point, implement at least 2 creational design patterns in your project.

## Implementation:

#### Singleton Design Pattern 

The AdoptionCenterSingleton class implements the singleton pattern.It ensures that there is only one instance of AdoptionCenter created by providing a static method(getInstance) that creates the instance if it doesn't exist. 
```cpp
class AdoptionCenterSingleton {
private:
    
    AdoptionCenterSingleton() {}

    static AdoptionCenter* instance; // singleton instance

    AdoptionCenterSingleton(const AdoptionCenterSingleton&) = delete;
    AdoptionCenterSingleton& operator=(const AdoptionCenterSingleton&) = delete;
public:
    
    static AdoptionCenter* getInstance();

};

```

#### Factory Design Pattern 

In this class I defined static factory methods createDog and createCat that encapsulate the creation of IAnimal objects (Dog and Cat). These methods create and return instances of IAnimal, respecting the Factory Pattern.

```cpp
class AnimalFactory {
public:
    static IAnimal* createDog(const std::string& name, int age, const std::string& breed) {
        return new Dog(name, age, breed);
    }

    static IAnimal* createCat(const std::string& name, int age) {
        return new Cat(name, age);
    }
};

```


#### Builder Design Pattern

IAdoptionApplicationBuilder interface: defines the steps for building an adoption  application, and concrete builder(AdoptionApplicationBuilder) implement those steps.

```cpp
class IAdoptionApplicationBuilder {
public:
    virtual IAdoptionApplicationBuilder& setAdopter(Adopter* adopter) = 0;
    virtual IAdoptionApplicationBuilder& setAnimalName(const std::string& animalName) = 0;
    virtual IAdoptionApplicationBuilder& setApplicationDate(const std::string& applicationDate) = 0;
    virtual IAdoptionApplicationBuilder& setApplicationStatus(const std::string& applicationStatus) = 0;
    virtual IAdoptionApplication* build() = 0;
    virtual ~IAdoptionApplicationBuilder() {}
};
```
AdoptionApplicationDirector arranges the construction process using the builders.

```cpp
IAdoptionApplication* AdoptionApplicationDirector::buildDefaultApplication(Adopter* adopter, const std::string& animalName) {
    return builder_->setAdopter(adopter)
                   .setAnimalName(animalName)
                   .setApplicationDate("Not Assigned")
                   .setApplicationStatus("Not assigned")
                   .build();
}

IAdoptionApplication* AdoptionApplicationDirector::buildApprovedApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate) {
    return builder_->setAdopter(adopter)
                   .setAnimalName(animalName)
                   .setApplicationDate(applicationDate)
                   .setApplicationStatus("Approved")
                   .build();
}

IAdoptionApplication* AdoptionApplicationDirector::buildDeniedApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate) {
    return builder_->setAdopter(adopter)
                   .setAnimalName(animalName)
                   .setApplicationDate(applicationDate)
                   .setApplicationStatus("Denied")
                   .build();
}
```

## Results:

* Factory - created several animal objects using the factory desing pattern:

```cpp
IAnimal* dog1 = AnimalFactory::createDog("Buddy", 3, "Golden Retriever");
    IAnimal* cat = AnimalFactory::createCat("Whiskers", 2);
    IAnimal* dog2 = AnimalFactory::createDog("Tuzic", 5, "Bulldog");
    IAnimal* cat2 = AnimalFactory::createCat("Puffy", 5);
```

* Singleton - created one instante of the adoption center, as it adheres to singleton principle:


```cpp
IAdoptionCenter* center = AdoptionCenterSingleton::getInstance();
```

* Builder - used the builder pattern to create an Adoption Application for my Adoption Center:

```cpp
AdoptionApplicationBuilder builder;

AdoptionApplicationDirector director(&builder);

IAdoptionApplication* application1 = director.buildDefaultApplication(&adopter3, "Buddy");
IAdoptionApplication* application2 = director.buildApprovedApplication(&adopter2, "Whiskers", "2023-10-05");
IAdoptionApplication* application3 = director.buildDeniedApplication(&adopter1, "Puffy", "2023-10-06");

```


## Conclusion:

In conclusion I was able to implement three design patterns, Builder, Singleton, Factory. Implementing these pattern they allowed me create more efficient code, also using these patterns it has become easier to extend my code.

To sum up, studying these patterns has helped me build more efficient and readable code.
