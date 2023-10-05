#ifndef ADOPTION_APPLICATION_H
#define ADOPTION_APPLICATION_H

#include "iostream"
#include "../users/Adopter.h"
#include "IAdoptionApplication.h"

class AdoptionApplication : public IAdoptionApplication {
private:
    Adopter* adopter;
    std::string animalName;
    std::string applicationDate;
    std::string applicationStatus;

public:
    AdoptionApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate, const std::string& applicationStatus);
    void displayApplications() const;
};

#endif 
