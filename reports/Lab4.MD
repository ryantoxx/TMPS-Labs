# Topic: Behavioral Design Patterns
## Course: Software Design Techniques and Mechanisms
## Author: Chihai Nichita

---

## Theory:

Behavioral design patterns are a category of design patterns that focus on the interaction and communication between objects and classes. They provide a way to organize the behavior of objects in a way that is both flexible and reusable, while separating the responsibilities of objects from the specific implementation details. Behavioral design patterns address common problems encountered in object behavior, such as how to define interactions between objects, how to control the flow of messages between objects, or how to define algorithms and policies that can be reused across different objects and classes.

Some examples from this category of design patterns are :

Chain of Responsibility

Command

Interpreter

Iterator

Mediator

Observer

Strategy

## Objectives:

1. Study and understand the Behavioral Design Patterns.

2. As a continuation of the previous laboratory work, think about what communication between software entities might be involed in your system.

3. Create a new Project or add some additional functionalities using behavioral design patterns.

## Tasks:

1. Creating a new project or extending your last one project, implement at least 1 behavioral design pattern in your project:

The implemented design pattern should help to perform the tasks involved in your system.
The behavioral DPs can be integrated into you functionalities alongside the structural ones.
There should only be one client for the whole system.

2. Keep your files grouped (into packages/directories) by their responsibilities (an example project structure):

client;

domain;

utilities;

data(if applies);

    3. Document your work in a separate markdown file according to the requirements presented below (the structure can be extended of course):

Topic of the laboratory work.

Author.

Introduction/Theory/Motivation.

Implementation & Explanation (you can include code snippets as well):

Indicate the location of the code snippet.

Emphasize the main idea and motivate the usage of the pattern.

Results/Screenshots/Conclusions;

## Implementation:

### Observer Design Pattern ###

The **Observer** pattern is used to establish a one-to-many dependency between objects. In this implementation, IObserver is an interface for observers, and AdopterObserver is a concrete class that implements this interface. The AdoptionCenter acts as the subject, maintaining a list of observers and notifying them when changes occur.

```cpp
class IObserver {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~IObserver() {}
};

class AdopterObserver : public IObserver {
public:
    void update(const std::string& message) override {
        std::cout << adopterName << " received a notification: " << message << std::endl;
    }
    . . .
};
```

### Command Design Pattern ###

The **Command** pattern is used to encapsulate a request as an object, allowing for parameterization of clients with different requests, queuing of requests, and support for undoable operations. In this implementation, ICommand is an interface for commands, and AddAnimalCommand is a concrete class that implements this interface. The Adopter class uses commands to facilitate the adoption process.

```cpp
class ICommand {
public:
    virtual void execute() = 0;
    virtual ~ICommand() {}
};

class AddAnimalCommand : public ICommand {
public:
    void execute() override {
        center->addAnimal(animal);
    }
    . . .
};
```

### Strategy Design Pattern ###

The **Strategy** pattern is used to define a family of algorithms, encapsulate each algorithm, and make them interchangeable. In this implementation, ISortingStrategy is an interface for sorting strategies, and SortByAge and SortByName are concrete classes that implement this interface. The AdoptionCenter class has methods to set and execute different sorting strategies.

```cpp
class ISortingStrategy {
public:
    virtual void sort(std::vector<IAnimal*>& animals) const = 0;
    virtual ~ISortingStrategy() {}
};

class SortByAge : public ISortingStrategy {
public:
    void sort(std::vector<IAnimal*>& animals) const override {
        std::sort(animals.begin(), animals.end(), [](const IAnimal* a, const IAnimal* b) {
            return a->getAge() < b->getAge();
        });
    }
};

class SortByName : public ISortingStrategy {
public:
    void sort(std::vector<IAnimal*>& animals) const override {
        std::sort(animals.begin(), animals.end(), [](const IAnimal* a, const IAnimal* b) {
            return a->getName() < b->getName();
        });
    }
};
```

## Results:

* Observer 
```cpp
IObserver* johnObserver = new AdopterObserver("John");
IObserver* aliceObserver = new AdopterObserver("Alice");
IObserver* bobObserver = new AdopterObserver("Bob");
. . .
center->notifyObservers("Two new animals, Max and Mittens, have been added!");
```

* Command
```cpp
ICommand* command1 = new AddAnimalCommand(center, new Dog("Jack", 3, "Labrador"));
ICommand* command2 = new AddAnimalCommand(center, new Cat("Bella", 2));

adopter1.setCommand(command1);
adopter2.setCommand(command2);

adopter1.executeAdoptionCommand();
adopter2.executeAdoptionCommand();
```

* Strategy
```cpp
ISortingStrategy* sortByAgeStrategy = new SortByAge();
ISortingStrategy* sortByNameStrategy = new SortByName();

center->setSortingStrategy(sortByAgeStrategy);

std::cout << "\nAnimals before sorting:" << std::endl;
center->displayAnimals();

// sorting by age
center->performSort();
std::cout << "\nAnimals after sorting by age:" << std::endl;
center->displayAnimals();

center->setSortingStrategy(sortByNameStrategy);

// sorting by name
center->performSort();
std::cout << "\nAnimals after sorting by name:" << std::endl;
center->displayAnimals();
```

## Conclusion:

In conclusion I was able to implement three design patterns, Strategy, Observer, Command, Proxy. Implementing these pattern they allowed me create more efficient code, also using these patterns it has become easier to extend my code.

To sum up, studying these patterns has helped me build more efficient and readable code.

