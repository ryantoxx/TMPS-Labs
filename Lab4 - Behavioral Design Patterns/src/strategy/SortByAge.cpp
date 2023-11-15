#include "SortByAge.h"
#include <algorithm>

void SortByAge::sort(std::vector<IAnimal*>& animals) const {
    std::sort(animals.begin(), animals.end(), [](const IAnimal* a, const IAnimal* b) {
        return a->getAge() < b->getAge();
    });
}
