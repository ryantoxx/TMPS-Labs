#ifndef ADOPTION_CENTER_PROXY_H
#define ADOPTION_CENTER_PROXY_H

#include "../adoption/IAdoptionCenter.h" 
#include "../adoption/AdoptionCenter.h"

enum AccessLevel {
    ACCESS_VISITOR,
    ACCESS_ADOPTER
};

class AdoptionCenterProxy : public IAdoptionCenter {
public:
    AdoptionCenterProxy(const std::string& name, AccessLevel level);
    std::string getName() const override;
    void addAnimal(IAnimal* animal) override;
    void displayAnimals() const override;
    IAnimal* adoptAnimal(const std::string& animalName) override;
    ~AdoptionCenterProxy();

private:
    AdoptionCenter* realCenter;
    AccessLevel accessLevel;
};

#endif 
