#ifndef IADOPTION_APPLICATION_BUILDER_H
#define IADOPTION_APPLICATION_BUILDER_H

#include "iostream"
#include "../adoption/IAdoptionApplication.h"
#include "../users/Adopter.h"

class IAdoptionApplicationBuilder {
public:
    virtual IAdoptionApplicationBuilder& setAdopter(Adopter* adopter) = 0;
    virtual IAdoptionApplicationBuilder& setAnimalName(const std::string& animalName) = 0;
    virtual IAdoptionApplicationBuilder& setApplicationDate(const std::string& applicationDate) = 0;
    virtual IAdoptionApplicationBuilder& setApplicationStatus(const std::string& applicationStatus) = 0;
    virtual IAdoptionApplication* build() = 0;
    virtual ~IAdoptionApplicationBuilder() {}
};


#endif