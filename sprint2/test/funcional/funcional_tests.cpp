#include <cassert>
#include <cmath>
#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

static bool comparacaoValor(double valor, double esperado, double erro)
{
    return std::fabs(std::round(valor * 10000) - std::round(esperado * 10000)) < erro;
}
class ExponentialFlow : public Flow
{
public:
    ExponentialFlow(System *source, System *target)
        : Flow("exponential", source, target)
    {
    }

    double execute()
    {
        return 0.01 * this->getSource()->getValue();
    }
};

class LogisticalFlow : public Flow
{
public:
    LogisticalFlow(System *source, System *target)
        : Flow("logistical", source, target)
    {
    }

    double execute()
    {
        double p2 = this->getTarget()->getValue();
        return 0.01 * p2 * (1.0 - p2 / 70.0);
    }
};

class ComplexFlow : public Flow
{
public:
    ComplexFlow(const std::string &name, System *source, System *target)
        : Flow(name, source, target)
    {
    }

    double execute()
    {
        return 0.01 * this->getSource()->getValue();
    }
};

void exponentialFuncionalTest()
{
    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);

    ExponentialFlow flow(&pop1, &pop2);

    Model model;
    model.add(&pop1);
    model.add(&pop2);
    model.add(&flow);

    model.run(0, 100, 1);

    assert(comparacaoValor(pop1.getValue(), 36.6032341273, 0.0001));
    assert(comparacaoValor(pop2.getValue(), 63.3967658727, 0.0001));
}

void logisticalFuncionalTest()
{
    System p1("p1", 100.0);
    System p2("p2", 10.0);

    LogisticalFlow flow(&p1, &p2);

    Model model;
    model.add(&p1);
    model.add(&p2);
    model.add(&flow);

    model.run(0, 100, 1);

    assert(comparacaoValor(p1.getValue(), 88.2166603540, 0.0001));
    assert(comparacaoValor(p2.getValue(), 21.7833396460, 0.0001));
}

void complexFuncionalTest()
{
    System Q1("Q1", 100.0);
    System Q2("Q2", 0.0);
    System Q3("Q3", 100.0);
    System Q4("Q4", 0.0);
    System Q5("Q5", 0.0);

    ComplexFlow f("f", &Q1, &Q2);
    ComplexFlow g("g", &Q1, &Q3);
    ComplexFlow r("r", &Q2, &Q5);
    ComplexFlow t("t", &Q2, &Q3);
    ComplexFlow u("u", &Q3, &Q4);
    ComplexFlow v("v", &Q4, &Q1);

    Model model;
    model.add(&Q1);
    model.add(&Q2);
    model.add(&Q3);
    model.add(&Q4);
    model.add(&Q5);

    model.add(&f);
    model.add(&g);
    model.add(&r);
    model.add(&t);
    model.add(&u);
    model.add(&v);

    model.run(0, 100, 1);

    assert(comparacaoValor(Q1.getValue(), 31.8512, 0.0001));
    assert(comparacaoValor(Q2.getValue(), 18.4003, 0.0001));
    assert(comparacaoValor(Q3.getValue(), 77.1143, 0.0001));
    assert(comparacaoValor(Q4.getValue(), 56.1728, 0.0001));
    assert(comparacaoValor(Q5.getValue(), 16.4612, 0.0001));
}
