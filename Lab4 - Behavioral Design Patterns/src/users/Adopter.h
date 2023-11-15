#ifndef ADOPTER_H
#define ADOPTER_H

#include <iostream>
#include <string>
#include <vector>
#include "../adoption/IAdoptionCenter.h"
#include "../animals/IAnimal.h"
#include "../command/ICommand.h"

class Adopter {
private:
    std::string name;
    std::vector<IAnimal*> adoptedAnimals;
    ICommand* adoptionCommand;

public:
    Adopter(const std::string& name);
    std::string getName() const;
    void applyForAdoption(IAdoptionCenter* center, const std::string& animalName);
    void displayApplications() const;
    void setCommand(ICommand* command);
    void executeAdoptionCommand();
};


#endif 

