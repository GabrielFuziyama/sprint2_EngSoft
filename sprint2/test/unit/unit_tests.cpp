#include <cassert>
#include "unit_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

class testeFlow : public Flow
{
public:
    testeFlow(System *origem, System *destino)
        : Flow("teste", origem, destino)
    {
    }

    double execute()
    {
        return 1.0;
    }
};

void systemsUnitTest()
{
    System system("S1", 10.0);

    assert(system.getName() == "S1");
    assert(system.getValue() == 10.0);

    system.addValue(5.0);
    assert(system.getValue() == 15.0);

    system.removeValue(3.0);
    assert(system.getValue() == 12.0);

    system.setValue(20.0);
    assert(system.getValue() == 20.0);
}

void modeloUnitTest()
{
    System s1("S1", 10.0);
    System s2("S2", 0.0);
    testeFlow flow(&s1, &s2);

    Model model;
    model.add(&s1);
    model.add(&s2);
    model.add(&flow);

    assert(model.getSystem().size() == 2);
    assert(model.getFlows().size() == 1);
    assert(model.getSystem("S1") == &s1);
    assert(model.getSystem("S2") == &s2);
    assert(model.getSystem("INVALIDO") == 0);
}
