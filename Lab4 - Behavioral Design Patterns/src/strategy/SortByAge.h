#ifndef SORTBYAGE_H
#define SORTBYAGE_H

#include "ISortingStrategy.h"

class SortByAge : public ISortingStrategy {
public:
    void sort(std::vector<IAnimal*>& animals) const override;
};

#endif 
