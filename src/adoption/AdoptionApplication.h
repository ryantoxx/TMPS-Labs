#ifndef ADOPTION_APPLICATION_H
#define ADOPTION_APPLICATION_H

#include "iostream"
#include "../users/Adopter.h"

class AdoptionApplication {
public:
    AdoptionApplication(Adopter* adopter, const std::string& animalName);
    void display() const;

private:
    Adopter* adopter;
    std::string animalName;
};

#endif 
