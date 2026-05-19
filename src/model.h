#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "system.h"
#include "flow.h"

class Model
{
private:
    std::vector<System*> sistema;
    std::vector<Flow*> flows;

public:
    Model();

    void add(System* sistema);
    void add(Flow* flow);

    std::vector<System*> getSistema() const;
    std::vector<Flow*> getFlows() const;

    System* getSistema(const std::string& name) const;

    void run(int start, int end, int step);
};

#endif
