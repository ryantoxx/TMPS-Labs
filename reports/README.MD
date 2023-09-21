# Topic: SOLID Principles
## Course: Software Design Techniques and Mechanisms
## Author: Chihai Nichita

---

## Theory:
**The SOLID Principles are five principles of Object-Oriented class design. They are a set of rules and best practices to follow while designing a class structure**

- The Single Responsibility Principle:

    * The Single Responsibility Principle states that a class should do one thing and therefore it should have only a single reason to change.This means that if a class is a data container, like a Book class or a Student class, and it has some fields regarding that entity, it should change only when we change the data model.

- Open-Closed Principle:

    - The Open-Closed Principle requires that classes should be open for extension and closed to modification.We should be able to add new functionality without touching the existing code for the class. This is because whenever we modify the existing code, we are taking the risk of creating potential bugs. So we should avoid touching the tested and reliable (mostly) production code if possible.

- Liskov Substitution Principle

    - The Liskov Substitution Principle states that subclasses should be substitutable for their base classes.This means that, given that class B is a subclass of class A, we should be able to pass an object of class B to any method that expects an object of class A and the method should not give any weird output in that case.

- Interface Segregation Principle
    - Segregation means keeping things separated, and the Interface Segregation Principle is about separating the interfaces.The principle states that many client-specific interfaces are better than one general-purpose interface. Clients should not be forced to implement a function they do no need.

-  Dependency Inversion Principle
    - The Dependency Inversion principle states that our classes should depend upon interfaces or abstract classes instead of concrete classes and functions.We want our classes to be open to extension, so we have reorganized our dependencies to depend on interfaces instead of concrete classes.

## Objectives:

1. Study and understand the SOLID Principles.
2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.
3. Create a sample project that respects SOLID Principles.

## Tasks:

1. Choose an OO programming language and a suitable IDE or Editor (No frameworks/libs/engines allowed).
2. Select a domain area for the sample project.
3. Define the main involved classes and think about what instantiation mechanisms are needed.
4. Respect SOLID Principles in your project.

## Implementation:

#### I have several classes that respect the *Single Responsibility  Principle*, for example: AdoptionCenter(collection of animals), Animal (name, age), Adopte(adopter, applying for adoption) classes. Each of them are responsible for certain actions.

```cpp
class Animal : public IAnimal {
private:
    std::string name;
    int age;

public:
    Animal(std::string, int age);

    std::string getName() const;
    int getAge() const;
    virtual void display() const;
    virtual void makeSound() const = 0;

};
``` 
```cpp
class AdoptionCenter : public IAdoptionCenter {
private:
    std::string name;
    std::vector<IAnimal*> animals;
public:
    AdoptionCenter(const std::string& name);
    std::string getName() const;
    void addAnimal(IAnimal* animal);
    void displayAnimals() const;
    IAnimal* adoptAnimal(const std::string& animalName);

};
```

#### For the *Open-Closed principle*, I can add new animals or adopters by creating new instances of these classes without changing my initial code. In my case I've created two new classes, Cat and Dog that are extensions of my base class Animal.

```cpp
class Dog : public Animal {
    private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& breed);

    void makeSound() const override;
    void display() const override;

};
```

```cpp
class Cat : public Animal {
public:
    Cat(const std::string& name, int age);

    void makeSound() const override;
};
```

#### The classes Cat and Dog have the method display() which follows the *Liskov Substitution Principle* which states that the derived class should be used interchageably with base class.
```cpp
class Animal : public IAnimal {
private:
    std::string name;
    int age;

public:
    Animal(std::string, int age);

    std::string getName() const;
    int getAge() const;
    virtual void display() const;
    virtual void makeSound() const = 0;

};
```
#### I can call the functions display() and makeSound() for the derived classes of Animal.

```cpp
    dog1->display();
    dog1->makeSound();
    cat->display();
    cat->makeSound();
    dog2->display();
    dog2->makeSound();
```

#### *Interface Segreagation Principle*, I've created several interfaces that have specific roles. 
```cpp
class IAdoptionCenter {
public:
    virtual std::string getName() const = 0;
    virtual void addAnimal(IAnimal* animal) = 0;
    virtual void displayAnimals() const = 0;
    virtual IAnimal* adoptAnimal(const std::string& animalName) = 0;
    virtual ~IAdoptionCenter() {}
};

```

```cpp
class IAnimal {
public:
    virtual std::string getName() const = 0;
    virtual int getAge() const = 0;
    virtual void display() const = 0;
    virtual void makeSound() const = 0;
    virtual ~IAnimal() {}
};
```

#### *Dependancy Inversion Principle*, the Adopter class depends on IAdoptionCenter class rather a specific implementation. Here, IAdoptionCenter is an abstract concept, and the actual center instance can be of any class derived from this abstract base class.

```cpp
void Adopter::applyForAdoption(IAdoptionCenter* center, const std::string& animalName) {
    IAnimal* adoptedAnimal = center->adoptAnimal(animalName);
        if (adoptedAnimal != nullptr) {
            adoptedAnimals.push_back(adoptedAnimal);
            std::cout << "\n" << name << " has adopted " << animalName << std::endl;
        } else {
            std::cout << "\n" << name << " could not adopt " << animalName << std::endl;
        }
}

```

## Results:

![Running the simulation](https://github.com/ryantoxx/TMPS-Labs/blob/main/imgs/result.png)

## Conclusion:
In conclusion the SOLID principles are a great way of improving the code, this principles provide a set of rules that keep the code robust, adaptable and maintainable. These principles emphasizes fundamental aspects of software design, improving the development of clean, extensible and easily understandable code.

