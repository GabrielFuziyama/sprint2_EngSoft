#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include <iostream>
#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

int main()
{
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    std::cout << "Todos os testes funcionais passaram!" << std::endl;

    return 0;
}

#endif
