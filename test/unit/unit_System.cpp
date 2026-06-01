#include "unit_System.h"
#include "../../src/systemImpl.h"
#include <assert.h>
#include <cmath>

void unit_System_constructor(void) {
    // Teste construtor padrão
    System* s1 = new SystemImpl();
    assert(s1->getName() == "");
    assert(s1->getValue() == 0.0);
    delete s1;

    // Teste construtor parametrizado
    System* s2 = new SystemImpl("TestSystem", 50.5);
    assert(s2->getName() == "TestSystem");
    assert(s2->getValue() == 50.5);
    delete s2;
}

void unit_System_destructor(void) {
    // Verificação conceitual/métrica se deleta sem quebras
    System* s = new SystemImpl("Delete", 10.0);
    delete s;
    assert(true); 
}

void unit_System_setValue(void) {
    System* s = new SystemImpl();
    s->setValue(123.45);
    assert(std::abs(s->getValue() - 123.45) < 0.0001);
    delete s;
}

void unit_System_getValue(void) {
    System* s = new SystemImpl("GetVal", 99.9);
    assert(std::abs(s->getValue() - 99.9) < 0.0001);
    delete s;
}

void unit_System_setName(void) {
    System* s = new SystemImpl();
    s->setName("NovoNome");
    assert(s->getName() == "NovoNome");
    delete s;
}

void unit_System_getName(void) {
    System* s = new SystemImpl("NomeFixo", 0.0);
    assert(s->getName() == "NomeFixo");
    delete s;
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_setValue();
    unit_System_getValue();
    unit_System_setName();
    unit_System_getName();
}