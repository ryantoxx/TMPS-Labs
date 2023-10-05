#ifndef ADOPTION_APPLICATION_BUILDER_H
#define ADOPTION_APPLICATION_BUILDER_H

#include "IAdoptionApplicationBuilder.h"
#include "../users/Adopter.h"

class AdoptionApplicationBuilder : public IAdoptionApplicationBuilder {
private:
    Adopter* adopter_;
    std::string animalName_;
    std::string applicationDate_;
    std::string applicationStatus_;

public:
    AdoptionApplicationBuilder();

    IAdoptionApplicationBuilder& setAdopter(Adopter* adopter) override;
    IAdoptionApplicationBuilder& setAnimalName(const std::string& animalName) override;
    IAdoptionApplicationBuilder& setApplicationDate(const std::string& applicationDate) override;
    IAdoptionApplicationBuilder& setApplicationStatus(const std::string& applicationStatus) override;
    IAdoptionApplication* build() override;

};

#endif
