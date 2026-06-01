#include "model.h"

Model::Model()
{
}

Model::Model(const Model &other)
{
    this->systems = other.systems;
    this->flows = other.flows;
}

Model::~Model()
{
}

Model &Model::operator=(const Model &other)
{
    if (this == &other)
    {
        return *this;
    }

    this->systems = other.systems;
    this->flows = other.flows;

    return *this;
}

void Model::add(System *system)
{
    this->systems.push_back(system);
}

void Model::add(Flow *flow)
{
    this->flows.push_back(flow);
}

std::vector<System *> Model::getSystem() const
{
    return this->systems;
}

std::vector<Flow *> Model::getFlows() const
{
    return this->flows;
}

System *Model::getSystem(const std::string &name) const
{
    for (unsigned int i = 0; i < this->systems.size(); i++)
    {
        if (this->systems[i]->getName() == name)
        {
            return this->systems[i];
        }
    }

    return nullptr;
}

void Model::run(int start, int end, int step)
{
    if (step <= 0 || end <= start)
    {
        return;
    }

    for (int currentTime = start; currentTime < end; currentTime += step)
    {
        std::vector<double> values;

        for (unsigned int i = 0; i < this->flows.size(); i++)
        {
            values.push_back(this->flows[i]->execute());
        }

        for (unsigned int i = 0; i < this->flows.size(); i++)
        {
            Flow *flow = this->flows[i];
            double value = values[i];

            if (flow->getSource() != nullptr)
            {
                flow->getSource()->removeValue(value);
            }

            if (flow->getTarget() != nullptr)
            {
                flow->getTarget()->addValue(value);
            }
        }
    }
}
