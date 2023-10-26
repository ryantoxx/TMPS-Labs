#ifndef ADOPTIONAPPLICATIONDECORATOR_H
#define ADOPTIONAPPLICATIONDECORATOR_H

#include <string>
#include "../adoption/IAdoptionApplication.h"

class AdoptionApplicationDecorator : public IAdoptionApplication {
private:
    IAdoptionApplication* application;
    std::string message;
public:
    AdoptionApplicationDecorator(IAdoptionApplication* application, const std::string& message);

    void display() const override;

};

#endif
