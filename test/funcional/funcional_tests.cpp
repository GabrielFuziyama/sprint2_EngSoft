#include "funcional_tests.h"
#include "../../src/systemImpl.h"
#include "../../src/modelImpl.h"
#include "../../src/exponentialFlow.h"
#include "../../src/logisticalFlow.h"
#include "../../src/complexFlow.h"
#include <iostream>
#include <assert.h>
#include <cmath>

void exponentialFuncionalTest() {
    System* pop1 = new SystemImpl("População 1", 100.0);
    System* pop2 = new SystemImpl("População 2", 0.0);
    Flow* expFlow = new ExponentialFlow("Fluxo Exponencial", pop1, pop2);
    Model* m = new ModelImpl("Modelo Exponencial");

    m->add(pop1);
    m->add(pop2);
    m->add(expFlow);

    m->run(0, 100, 1);

    assert(std::abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(std::abs(pop2->getValue() - 63.3968) < 0.0001);

    delete m;
    delete expFlow;
    delete pop1;
    delete pop2;
}

void logisticalFuncionalTest() {
    System* p1 = new SystemImpl("P1", 100.0);
    System* p2 = new SystemImpl("P2", 10.0);
    Flow* logFlow = new LogisticalFlow("Fluxo Logístico", p1, p2);
    Model* m = new ModelImpl("Modelo Logístico");

    m->add(p1);
    m->add(p2);
    m->add(logFlow);

    m->run(0, 100, 1);

    assert(std::abs(p1->getValue() - 88.2167) < 0.0001);
    assert(std::abs(p2->getValue() - 21.7833) < 0.0001);

    delete m;
    delete logFlow;
    delete p1;
    delete p2;
}

void complexFuncionalTest() {
    System* q1 = new SystemImpl("Q1", 100.0);
    System* q2 = new SystemImpl("Q2", 0.0);
    System* q3 = new SystemImpl("Q3", 100.0);
    System* q4 = new SystemImpl("Q4", 0.0);
    System* q5 = new SystemImpl("Q5", 0.0);

    Flow* f = new ComplexFlow("f", q1, q2);
    Flow* g = new ComplexFlow("g", q1, q3);
    Flow* r = new ComplexFlow("r", q2, q5);
    Flow* t = new ComplexFlow("t", q2, q3);
    Flow* u = new ComplexFlow("u", q3, q4);
    Flow* v = new ComplexFlow("v", q4, q1);

    Model* m = new ModelImpl("Modelo Complexo");
    m->add(q1); m->add(q2); m->add(q3); m->add(q4); m->add(q5);
    m->add(f);  m->add(g);  m->add(r);  m->add(t);  m->add(u);  m->add(v);

    m->run(0, 100, 1);

    assert(std::abs(q1->getValue() - 31.8513) < 0.0001);
    assert(std::abs(q2->getValue() - 18.4003) < 0.0001);
    assert(std::abs(q3->getValue() - 77.1143) < 0.0001);
    assert(std::abs(q4->getValue() - 56.1728) < 0.0001);
    assert(std::abs(q5->getValue() - 16.4612) < 0.0001);

    delete m;
    delete f; delete g; delete r; delete t; delete u; delete v;
    delete q1; delete q2; delete q3; delete q4; delete q5;
}