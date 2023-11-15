#ifndef SORTBYNAME_H
#define SORTBYNAME_H

#include "ISortingStrategy.h"

class SortByName : public ISortingStrategy {
public:
    void sort(std::vector<IAnimal*>& animals) const override;
};

#endif 
