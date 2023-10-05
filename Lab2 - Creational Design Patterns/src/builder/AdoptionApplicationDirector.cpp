#include "AdoptionApplicationDirector.h"

AdoptionApplicationDirector::AdoptionApplicationDirector(IAdoptionApplicationBuilder* builder)
    : builder_(builder) {

}

IAdoptionApplication* AdoptionApplicationDirector::buildDefaultApplication(Adopter* adopter, const std::string& animalName) {
    return builder_->setAdopter(adopter)
                   .setAnimalName(animalName)
                   .setApplicationDate("Not Assigned")
                   .setApplicationStatus("Not assigned")
                   .build();
}

IAdoptionApplication* AdoptionApplicationDirector::buildApprovedApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate) {
    return builder_->setAdopter(adopter)
                   .setAnimalName(animalName)
                   .setApplicationDate(applicationDate)
                   .setApplicationStatus("Approved")
                   .build();
}

IAdoptionApplication* AdoptionApplicationDirector::buildDeniedApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate) {
    return builder_->setAdopter(adopter)
                   .setAnimalName(animalName)
                   .setApplicationDate(applicationDate)
                   .setApplicationStatus("Denied")
                   .build();
}
