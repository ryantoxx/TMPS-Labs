#include "AdoptionApplication.h"

AdoptionApplication::AdoptionApplication(Adopter* adopter, const std::string& animalName, const std::string& applicationDate, const std::string& applicationStatus)
    : adopter(adopter), animalName(animalName), applicationDate(applicationDate), applicationStatus(applicationStatus){}

void AdoptionApplication::displayApplications() const {
    std::cout << "Adopter: " << adopter->getName()
                << ", Animal: " << animalName
                << ", Application Date: " << applicationDate
                << ", Application Status: " << applicationStatus << std::endl;
}
