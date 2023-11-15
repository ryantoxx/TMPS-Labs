#include "AddAnimalCommand.h"

AddAnimalCommand::AddAnimalCommand(IAdoptionCenter* center, IAnimal* animal)
    : center(center), animal(animal) {}

void AddAnimalCommand::execute() {
    center->addAnimal(animal);
}
