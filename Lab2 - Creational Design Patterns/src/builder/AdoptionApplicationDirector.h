#ifndef ADOPTION_APPLICATION_DIRECTOR_H
#define ADOPTION_APPLICATION_DIRECTOR_H

#include "IAdoptionApplicationBuilder.h"
#include "../adoption/AdoptionApplication.h"
#include "../users/Adopter.h" 

class AdoptionApplicationDirector {
private:
    IAdoptionApplicationBuilder* builder_;
public:
    AdoptionApplicationDirector(IAdoptionApplicationBuilder* builder);

    IAdoptionApplication* buildDefaultApplication(Adopter* adopter, const std::string& animalName);
    IAdoptionApplication* buildApprovedApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate);
    IAdoptionApplication* buildDeniedApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate);
};

#endif 
