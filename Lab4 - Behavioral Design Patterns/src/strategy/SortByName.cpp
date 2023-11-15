#include "SortByName.h"
#include <algorithm>

void SortByName::sort(std::vector<IAnimal*>& animals) const {
    std::sort(animals.begin(), animals.end(), [](const IAnimal* a, const IAnimal* b) {
        return a->getName() < b->getName();
    
    });
}
