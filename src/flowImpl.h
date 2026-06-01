#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "flow.h"

class FlowImpl : public Flow {
protected:
    std::string name;
    System* source;
    System* target;
public:
    FlowImpl();
    FlowImpl(std::string name, System* source, System* target);
    virtual ~FlowImpl();

    void setSource(System* source);
    System* getSource() const;
    void setTarget(System* target);
    System* getTarget() const;
    void setName(std::string name);
    std::string getName() const;
    virtual double execute() = 0; // Continua puro para as classes filhas (ex: Exponential)

    FlowImpl(const FlowImpl& other);
    FlowImpl& operator=(const FlowImpl& other);
};

#endif