#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model.h"

class ModelImpl : public Model {
protected:
    std::string name;
    std::vector<System*> systems;
    std::vector<Flow*> flows;
public:
    ModelImpl();
    ModelImpl(std::string name);
    virtual ~ModelImpl();

    void add(System* sys);
    void add(Flow* flow);
    void setName(std::string name);
    std::string getName() const;
    void run(int start, int end, int step);

    systemIterator beginSystems();
    systemIterator endSystems();
    flowIterator beginFlows();
    flowIterator endFlows();

private:
    ModelImpl(const ModelImpl& other);
    ModelImpl& operator=(const ModelImpl& other);
};

#endif