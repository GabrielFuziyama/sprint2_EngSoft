#include "model.h"

Model::Model()
{
}

void Model::add(System *system)
{
    this->sistema.push_back(system);
}

void Model::add(Flow *flow)
{
    this->flows.push_back(flow);
}

std::vector<System *> Model::getSistema() const
{
    return this->sistema;
}

std::vector<Flow *> Model::getFlows() const
{
    return this->flows;
}

System *Model::getSistema(const std::string &name) const
{
    for (unsigned int i = 0; i < this->sistema.size(); i++)
    {
        if (this->sistema[i]->getNome() == name)
        {
            return this->sistema[i];
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

            if (flow->getOrigem() != 0)
            {
                flow->getOrigem()->removeValor(value);
            }

            if (flow->getDestino() != 0)
            {
                flow->getDestino()->addValor(value);
            }
        }
    }
}
