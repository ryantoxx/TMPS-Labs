#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <iostream>
#include <vector>

class IObserver {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~IObserver() {}
};

#endif