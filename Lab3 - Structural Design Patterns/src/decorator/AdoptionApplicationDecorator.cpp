#include "AdoptionApplicationDecorator.h"
#include <iostream>

AdoptionApplicationDecorator::AdoptionApplicationDecorator(IAdoptionApplication* application, const std::string& message)
    : application(application), message(message) {}

void AdoptionApplicationDecorator::display() const {
    application->display(); 
    std::cout << "Additional Message: " << message << std::endl;
}
