#include "unit_Flow.h"
#include "../../src/flowImpl.h"
#include "../../src/systemImpl.h"
#include <assert.h>

// Subclasse mock para testar a classe abstrata FlowImpl
class ExemploTestFlow : public FlowImpl {
public:
    ExemploTestFlow() : FlowImpl() {}
    ExemploTestFlow(std::string name, System* src, System* tgt) : FlowImpl(name, src, tgt) {}
    double execute() {
        if (getSource() != nullptr) return getSource()->getValue() * 0.1;
        return 0.0;
    }
};

void unit_Flow_constructor(void) {
    Flow* f1 = new ExemploTestFlow();
    assert(f1->getName() == "");
    assert(f1->getSource() == nullptr);
    assert(f1->getTarget() == nullptr);
    delete f1;

    System* s1 = new SystemImpl("S1", 10.0);
    System* s2 = new SystemImpl("S2", 0.0);
    Flow* f2 = new ExemploTestFlow("F2", s1, s2);
    assert(f2->getName() == "F2");
    assert(f2->getSource() == s1);
    assert(f2->getTarget() == s2);
    
    delete f2;
    delete s1;
    delete s2;
}

void unit_Flow_destructor(void) {
    Flow* f = new ExemploTestFlow();
    delete f;
    assert(true);
}

void unit_Flow_setSource(void) {
    Flow* f = new ExemploTestFlow();
    System* s = new SystemImpl("Origem", 50.0);
    f->setSource(s);
    assert(f->getSource() == s);
    delete f;
    delete s;
}

void unit_Flow_getSource(void) {
    System* s = new SystemImpl("Origem", 50.0);
    Flow* f = new ExemploTestFlow("F", s, nullptr);
    assert(f->getSource()->getName() == "Origem");
    delete f;
    delete s;
}

void unit_Flow_setTarget(void) {
    Flow* f = new ExemploTestFlow();
    System* s = new SystemImpl("Destino", 0.0);
    f->setTarget(s);
    assert(f->getTarget() == s);
    delete f;
    delete s;
}

void unit_Flow_getTarget(void) {
    System* s = new SystemImpl("Destino", 0.0);
    Flow* f = new ExemploTestFlow("F", nullptr, s);
    assert(f->getTarget()->getName() == "Destino");
    delete f;
    delete s;
}

void unit_Flow_setName(void) {
    Flow* f = new ExemploTestFlow();
    f->setName("FluxoAlterado");
    assert(f->getName() == "FluxoAlterado");
    delete f;
}

void unit_Flow_getName(void) {
    Flow* f = new ExemploTestFlow("FluxoFixo", nullptr, nullptr);
    assert(f->getName() == "FluxoFixo");
    delete f;
}

void unit_Flow_execute(void) {
    System* s1 = new SystemImpl("S1", 100.0);
    Flow* f = new ExemploTestFlow("F", s1, nullptr);
    assert(f->execute() == 10.0);
    delete f;
    delete s1;
}

void run_unit_tests_Flow(void) {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_setSource();
    unit_Flow_getSource();
    unit_Flow_setTarget();
    unit_Flow_getTarget();
    unit_Flow_setName();
    unit_Flow_getName();
    unit_Flow_execute();
}