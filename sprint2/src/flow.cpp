#include "flow.h"

Flow::Flow()
{
    this->name = "";
    this->origem = 0;
    this->destino = 0;
}

Flow::Flow(const std::string &name, System *origem, System *destino)
{
    this->name = name;
    this->origem = origem;
    this->destino = destino;
}

Flow::~Flow()
{
}

std::string Flow::getName() const
{
    return this->name;
}

void Flow::setName(const std::string &name)
{
    this->name = name;
}

System *Flow::getSource() const
{
    return this->origem;
}
Flow::Flow(const Flow &other)
{
    this->name = other.name;
    this->origem = other.origem;
    this->destino = other.destino;
}
void Flow::setSource(System *origem)
{
    this->origem = origem;
}

System *Flow::getTarget() const
{
    return this->destino;
}

void Flow::setTarget(System *destino)
{
    this->destino = destino;
}
