#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H

#include "flowImpl.h"

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow();
    ExponentialFlow(std::string name, System* source, System* target);
    virtual ~ExponentialFlow();
    virtual double execute();
};

#endif