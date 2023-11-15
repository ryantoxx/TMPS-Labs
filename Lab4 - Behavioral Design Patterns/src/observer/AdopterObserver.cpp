#include "AdopterObserver.h"

AdopterObserver::AdopterObserver(const std::string& adopterName) : adopterName(adopterName) {}

void AdopterObserver::update(const std::string& message) {
    std::cout << "\n" <<adopterName << " received a notification: " << message << std::endl;
}
