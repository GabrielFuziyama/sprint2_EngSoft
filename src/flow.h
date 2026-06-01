#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow {
public:
    virtual ~Flow() {}
    virtual void setSource(System* source) = 0;
    virtual System* getSource() const = 0;
    virtual void setTarget(System* target) = 0;
    virtual System* getTarget() const = 0;
    virtual void setName(std::string name) = 0;
    virtual std::string getName() const = 0;
    virtual double execute() = 0; // Método virtual puro da equação matemática
};

#endif