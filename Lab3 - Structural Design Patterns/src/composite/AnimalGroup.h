#ifndef ANIMAL_GROUP_H
#define ANIMAL_GROUP_H

#include <string>
#include <vector>
#include "../animals/IAnimal.h"

class AnimalGroup : public IAnimal {
private:
    std::string groupName;
    std::vector<IAnimal*> animals;
public:
    AnimalGroup(const std::string& groupName);

    void addAnimal(IAnimal* animal);

    std::string getName() const override;

    int getAge() const override;

    void display() const override;

    void makeSound() const override;
};

#endif 
