#include "AdoptionCenterSingleton.h"
#include "../adoption/AdoptionCenter.h" 

AdoptionCenter* AdoptionCenterSingleton::instance = nullptr;

// Static method to access the singleton instance
AdoptionCenter* AdoptionCenterSingleton::getInstance() {
    // Create the instance if it doesn't exist
    if (instance == nullptr) {
        instance = new AdoptionCenter("Pet Adoption Center");
    }
    return instance;
}
