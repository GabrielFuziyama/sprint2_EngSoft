#include "unit_Model.h"
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../src/flowImpl.h"
#include <assert.h>

class ModelTestFlow : public FlowImpl {
public:
    ModelTestFlow(std::string name, System* src, System* tgt) : FlowImpl(name, src, tgt) {}
    double execute() { return 2.0; } 
};

void unit_Model_constructor(void) {
    Model* m1 = new ModelImpl();
    assert(m1->getName() == "");
    delete m1;

    Model* m2 = new ModelImpl("SimuladorEcologico");
    assert(m2->getName() == "SimuladorEcologico");
    delete m2;
}

void unit_Model_destructor(void) {
    Model* m = new ModelImpl();
    delete m;
    assert(true);
}

void unit_Model_addSystem(void) {
    Model* m = new ModelImpl();
    System* s = new SystemImpl("S1", 10.0);
    m->add(s);
    
    auto it = m->beginSystems();
    assert(*it == s);
    delete m;
    delete s;
}

void unit_Model_addFlow(void) {
    Model* m = new ModelImpl();
    Flow* f = new ModelTestFlow("F1", nullptr, nullptr);
    m->add(f);
    
    auto it = m->beginFlows();
    assert(*it == f);
    delete m;
    delete f;
}

void unit_Model_setName(void) {
    Model* m = new ModelImpl();
    m->setName("NovoModelo");
    assert(m->getName() == "NovoModelo");
    delete m;
}

void unit_Model_getName(void) {
    Model* m = new ModelImpl("NomeOriginal");
    assert(m->getName() == "NomeOriginal");
    delete m;
}

void unit_Model_run(void) {
    Model* m = new ModelImpl();
    System* s1 = new SystemImpl("S1", 10.0);
    System* s2 = new SystemImpl("S2", 0.0);
    Flow* f = new ModelTestFlow("F", s1, s2);
    
    m->add(s1);
    m->add(s2);
    m->add(f);
    
    m->run(0, 1, 1); // 1 iteração -> transfere 2.0
    assert(s1->getValue() == 8.0);
    assert(s2->getValue() == 2.0);
    
    delete m;
    delete f;
    delete s1;
    delete s2;
}

void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_addSystem();
    unit_Model_addFlow();
    unit_Model_setName();
    unit_Model_getName();
    unit_Model_run();
}