#include "model.h"

Model::Model()
{
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

    return 0;
}

void Model::run(int start, int end, int step)
{
    if (step <= 0)
    {
        return;
    }

    int numberOfSteps = (end - start) / step;

    for (int currentStep = 0; currentStep < numberOfSteps; currentStep++)
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

            if (flow->getSource() != 0)
            {
                flow->getSource()->removeValue(value);
            }

            if (flow->getTarget() != 0)
            {
                flow->getTarget()->addValue(value);
            }
        }
    }
}
