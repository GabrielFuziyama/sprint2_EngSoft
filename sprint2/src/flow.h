#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow
{
protected:
    std::string name;
    System *origem;
    System *destino;

public:
    Flow();
    Flow(const std::string &name, System *origem, System *destino);

    Flow(const Flow &other);
    virtual ~Flow();
    Flow &operator=(const Flow &other);

    std::string getName() const;
    void setName(const std::string &name);

    System *getSource() const;
    void setSource(System *origem);

    System *getTarget() const;
    void setTarget(System *destino);

    virtual double execute() = 0;
};

#endif