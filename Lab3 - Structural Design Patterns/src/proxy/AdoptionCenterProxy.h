#ifndef ADOPTION_CENTER_PROXY_H
#define ADOPTION_CENTER_PROXY_H

#include "../adoption/IAdoptionCenter.h" 
#include "../adoption/AdoptionCenter.h"

enum AccessLevel {
    ACCESS_VISITOR,
    ACCESS_ADOPTER
};

class AdoptionCenterProxy : public IAdoptionCenter {
private:
    AdoptionCenter* realCenter;
    AccessLevel accessLevel;
public:
    AdoptionCenterProxy(const std::string& name, AccessLevel level);
    std::string getName() const override;
    void addAnimal(IAnimal* animal) override;
    void displayAnimals() const override;
    IAnimal* adoptAnimal(const std::string& animalName) override;
    ~AdoptionCenterProxy();
};

#endif 
