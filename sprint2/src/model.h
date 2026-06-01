#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "system.h"
#include "flow.h"

class Model
{
private:
    std::vector<System *> systems;
    std::vector<Flow *> flows;

public:
    Model();

    // Forma canonica
    Model(const Model &other);
    virtual ~Model();
    Model &operator=(const Model &other);

    void add(System *system);
    void add(Flow *flow);

    std::vector<System *> getSystem() const;
    std::vector<Flow *> getFlows() const;
    System *getSystem(const std::string &name) const;

    void run(int start, int end, int step);
};

#endif
