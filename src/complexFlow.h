#ifndef COMPLEXFLOW_H
#define COMPLEXFLOW_H

#include "flowImpl.h"

class ComplexFlow : public FlowImpl {
public:
    ComplexFlow();
    ComplexFlow(std::string name, System* source, System* target);
    virtual ~ComplexFlow();
    virtual double execute();
};

#endif