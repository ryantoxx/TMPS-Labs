#ifndef ADOPTION_APPLICATION_H
#define ADOPTION_APPLICATION_H

#include "iostream"
#include "../users/Adopter.h"
#include "IAdoptionApplication.h"

class AdoptionApplication : public IAdoptionApplication {
private:
    Adopter* adopter;
    std::string animalName;

public:
    AdoptionApplication(Adopter* adopter, const std::string& animalName);
    void displayApplications() const;
};

#endif 
