#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "system.h"
#include "flow.h"

class Model {
public:
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator flowIterator;

    virtual ~Model() {}
    virtual void add(System* sys) = 0;
    virtual void add(Flow* flow) = 0;
    virtual void setName(std::string name) = 0;
    virtual std::string getName() const = 0;
    virtual void run(int start, int end, int step) = 0;

    virtual systemIterator beginSystems() = 0;
    virtual systemIterator endSystems() = 0;
    virtual flowIterator beginFlows() = 0;
    virtual flowIterator endFlows() = 0;
};

#endif