#include <iostream>
#include "mySim.h"

class DemoFlow : public Flow
{
public:
    DemoFlow(const std::string &name, System *origem, System *destino)
        : Flow(name, origem, destino)
    {
    }

    double execute()
    {
        return 0.01 * this->getSource()->getValue();
    }
};

int main()
{
    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);

    DemoFlow flow("flow", &pop1, &pop2);

    Model model;
    model.add(&pop1);
    model.add(&pop2);
    model.add(&flow);

    model.run(0, 100, 1);

    std::cout << "pop1 = " << pop1.getValue() << std::endl;
    std::cout << "pop2 = " << pop2.getValue() << std::endl;

    return 0;
}
