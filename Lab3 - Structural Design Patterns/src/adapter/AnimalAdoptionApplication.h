#ifndef ANIMAL_ADOPTION_APPLICATION_H
#define ANIMAL_ADOPTION_APPLICATION_H

#include "../users/Adopter.h"
#include "../adoption/IAdoptionApplication.h"
#include "../animals/IAnimal.h"


class AnimalAdoptionApplication : public IAdoptionApplication {
private:
    Adopter* adopter;
    IAnimal* animal;
public:
    AnimalAdoptionApplication(Adopter* adopter, IAnimal* animal);

    void display() const override;

};

#endif 
