#ifndef IANIMAL_PROTOTYPE_H
#define IANIMAL_PROTOTYPE_H

class IAnimalPrototype {
public:
    virtual IAnimalPrototype* clone() const = 0;
    virtual ~IAnimalPrototype() {}
};

#endif 