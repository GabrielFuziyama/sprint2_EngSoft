/**
 * @file funcional_tests.h
 * @brief Assinaturas das rotinas de testes funcionais integrados da API.
 * @author Vítor de Sousa Costa Lopes e Gabriel Carneiro Gama Fuziyama
 * @date 2026
 */

#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

/**
 * @brief Executa a homologação do cenário clássico com crescimento exponencial simples.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa a homologação do cenário logístico com barreira de saturação/capacidade de carga.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa a validação do ecossistema complexo (Malha cíclica Q) interligando múltiplos sistemas.
 */
void complexFuncionalTest();

#endif