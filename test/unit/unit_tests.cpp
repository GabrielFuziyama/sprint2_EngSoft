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

void sistemaUnitTest()
{
    System system("S1", 10.0);

    assert(system.getNome() == "S1");
    assert(system.getValor() == 10.0);

    system.addValor(5.0);
    assert(system.getValor() == 15.0);

    system.removeValor(3.0);
    assert(system.getValor() == 12.0);

    system.setValor(20.0);
    assert(system.getValor() == 20.0);
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

    assert(model.getSistema().size() == 2);
    assert(model.getFlows().size() == 1);
    assert(model.getSistema("S1") == &s1);
    assert(model.getSistema("S2") == &s2);
    assert(model.getSistema("INVALIDO") == 0);
}
