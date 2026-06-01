#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"
#include "unit_tests.h"
#include <iostream>

int main() {
    std::cout << "============= INICIANDO TESTES UNITARIOS (SPRINT 4) =============" << std::endl;

    run_unit_tests_globals();
    std::cout << "[SUCCESS] Testes de funcoes globais concluidos." << std::endl;

    run_unit_tests_System();
    std::cout << "[SUCCESS] Testes unitarios da classe System concluidos." << std::endl;

    run_unit_tests_Flow();
    std::cout << "[SUCCESS] Testes unitarios da classe Flow concluidos." << std::endl;

    run_unit_tests_Model();
    std::cout << "[SUCCESS] Testes unitarios da classe Model concluidos." << std::endl;

    std::cout << "=================================================================" << std::endl;
    std::cout << "      TODOS OS TESTES UNITARIOS PASSARAM COM SUCESSO!            " << std::endl;
    std::cout << "=================================================================" << std::endl;

    return 0;
}