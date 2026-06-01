#include "flow.h"

Flow::Flow()
{
    this->name = "";
    this->origem = nullptr;
    this->destino = nullptr;
}

Flow::Flow(const std::string &name, System *origem, System *destino)
{
    this->name = name;
    this->origem = origem;
    this->destino = destino;
}

Flow::Flow(const Flow &other)
{
    this->name = other.name;
    this->origem = other.origem;
    this->destino = other.destino;
}

Flow::~Flow()
{
}

Flow &Flow::operator=(const Flow &other)
{
    if (this == &other)
    {
        return *this;
    }

    this->name = other.name;
    this->origem = other.origem;
    this->destino = other.destino;

    return *this;
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
