#ifndef ISORTING_STRATEGY_H
#define ISORTING_STRATEGY_H

#include <vector>
#include "../animals/IAnimal.h"

class ISortingStrategy {
public:
    virtual void sort(std::vector<IAnimal*>& animals) const = 0;
    virtual ~ISortingStrategy() {}

};

#endif