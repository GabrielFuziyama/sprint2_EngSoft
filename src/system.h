#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
public:
    virtual ~System() {}
    virtual void setValue(double value) = 0;
    virtual double getValue() const = 0;
    virtual void setName(std::string name) = 0;
    virtual std::string getName() const = 0;
};

#endif