#ifndef LOGISTICALFLOW_H
#define LOGISTICALFLOW_H

#include "flowImpl.h"

class LogisticalFlow : public FlowImpl {
public:
    LogisticalFlow();
    LogisticalFlow(std::string name, System* source, System* target);
    virtual ~LogisticalFlow();
    virtual double execute();
};

#endif