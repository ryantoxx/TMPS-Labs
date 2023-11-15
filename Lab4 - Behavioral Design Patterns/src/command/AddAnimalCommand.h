#ifndef ADD_ANIMAL_COMMAND_H
#define ADD_ANIMAL_COMMAND_H

#include "ICommand.h" 
#include "../adoption/IAdoptionCenter.h"
#include "../animals/IAnimal.h"

class AddAnimalCommand : public ICommand {
private:
    IAdoptionCenter* center;
    IAnimal* animal;
public:
    AddAnimalCommand(IAdoptionCenter* center, IAnimal* animal);
    void execute() override;

};

#endif 
