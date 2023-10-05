#include "AdoptionApplicationBuilder.h"
#include "../adoption/AdoptionApplication.h"


AdoptionApplicationBuilder::AdoptionApplicationBuilder() {

}

IAdoptionApplicationBuilder& AdoptionApplicationBuilder::setAdopter(Adopter* adopter) {
    adopter_ = adopter;
    return *this;
}

IAdoptionApplicationBuilder& AdoptionApplicationBuilder::setAnimalName(const std::string& animalName) {
    animalName_ = animalName;
    return *this;
}

IAdoptionApplicationBuilder& AdoptionApplicationBuilder::setApplicationDate(const std::string& applicationDate) {
    applicationDate_ = applicationDate;
    return *this;
}

IAdoptionApplicationBuilder& AdoptionApplicationBuilder::setApplicationStatus(const std::string& applicationStatus) {
    applicationStatus_ = applicationStatus;
    return *this;
}

IAdoptionApplication* AdoptionApplicationBuilder::build() {
    return new AdoptionApplication(adopter_, animalName_, applicationDate_, applicationStatus_);
}

