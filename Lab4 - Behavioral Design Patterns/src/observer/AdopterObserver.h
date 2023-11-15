#ifndef ADOPTEROBSERVER_H
#define ADOPTEROBSERVER_H

#include "IObserver.h"
#include <iostream>
#include <string>

class AdopterObserver : public IObserver {
private:
    std::string adopterName;
    
public:
    AdopterObserver(const std::string& adopterName);

    void update(const std::string& message) override;

};

#endif
