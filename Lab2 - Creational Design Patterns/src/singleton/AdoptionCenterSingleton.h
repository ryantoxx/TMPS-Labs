#ifndef ADOPTION_CENTER_SINGLETON_H
#define ADOPTION_CENTER_SINGLETON_H

#include  "../adoption/AdoptionCenter.h"

class AdoptionCenterSingleton {
private:
    
    AdoptionCenterSingleton() {}

    static AdoptionCenter* instance; // singleton instance

    AdoptionCenterSingleton(const AdoptionCenterSingleton&) = delete;
    AdoptionCenterSingleton& operator=(const AdoptionCenterSingleton&) = delete;
public:
    
    static AdoptionCenter* getInstance();

};

#endif 

