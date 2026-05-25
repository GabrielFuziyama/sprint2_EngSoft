/**
 * @file funcional_tests.cpp
 * @brief Implementação dos testes funcionais e das subclasses concretas de fluxo.
 * @author Vítor de Sousa Costa Lopes e Gabriel Carneiro Gama Fuziyama
 * @date 2026
 */

#include <cassert>
#include <cmath>
#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

/**
 * @brief Função auxiliar estática para comparação de valores em ponto flutuante usando Épsilon.
 * @param valor Valor real calculado pelo simulador.
 * @param esperado Valor de referência analítica/teórica esperada.
 * @param erro Margem de tolerância aceitável (Épsilon).
 * @return true Se a diferença absoluta for menor que a tolerância.
 * @return false Caso contrário.
 */
static bool comparacaoValor(double valor, double esperado, double erro)
{
    return std::fabs(valor - esperado) < erro;
}

/**
 * @class ExponentialFlow
 * @brief Subclasse concreta de Flow para modelagem de dinâmicas de crescimento ou decaimento exponencial.
 */
class ExponentialFlow : public Flow
{
public:
    /**
     * @brief Construtor da classe ExponentialFlow.
     * @param source Ponteiro para o estoque de origem.
     * @param target Ponteiro para o estoque de destino.
     */
    ExponentialFlow(System *source, System *target)
        : Flow("exponential", source, target)
    {
    }

    /**
     * @brief Equação matemática do fluxo exponencial.
     * Retorna 1% do valor acumulado no estoque de origem.
     * @return double Taxa de variação calculada.
     */
    double execute()
    {
        return 0.01 * this->getOrigem()->getValor();
    }
};

/**
 * @class LogisticalFlow
 * @brief Subclasse concreta de Flow para modelagem de crescimento limitado ou saturação logística.
 */
class LogisticalFlow : public Flow
{
public:
    /**
     * @brief Construtor da classe LogisticalFlow.
     * @param source Ponteiro para o estoque de origem.
     * @param target Ponteiro para o estoque de destino.
     */
    LogisticalFlow(System *source, System *target)
        : Flow("logistical", source, target)
    {
    }

    /**
     * @brief Equação matemática do fluxo logístico.
     * Calcula a taxa baseando-se no estoque de destino e no teto de sustentação igual a 70.0.
     * @return double Taxa de variação calculada.
     */
    double execute()
    {
        double p2 = this->getDestino()->getValor();
        return 0.01 * p2 * (1.0 - p2 / 70.0);
    }
};

/**
 * @class ComplexFlow
 * @brief Subclasse concreta de Flow para formação de redes cíclicas e interconexões complexas.
 */
class ComplexFlow : public Flow
{
public:
    /**
     * @brief Construtor da classe ComplexFlow.
     * @param name Identificador único do fluxo.
     * @param source Ponteiro para o estoque de origem.
     * @param target Ponteiro para o estoque de destino.
     */
    ComplexFlow(const std::string &name, System *source, System *target)
        : Flow(name, source, target)
    {
    }

    /**
     * @brief Equação matemática do fluxo complexo.
     * Retorna 1% do valor contido no estoque de origem.
     * @return double Taxa de variação calculada.
     */
    double execute()
    {
        return 0.01 * this->getOrigem()->getValor();
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

    assert(comparacaoValor(pop1.getValor(), 36.6032341273, 0.0001));
    assert(comparacaoValor(pop2.getValor(), 63.3967658727, 0.0001));
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

    assert(comparacaoValor(p1.getValor(), 88.2166603540, 0.0001));
    assert(comparacaoValor(p2.getValor(), 21.7833396460, 0.0001));
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

    assert(comparacaoValor(Q1.getValor(), 31.8512967948, 0.0001));
    assert(comparacaoValor(Q2.getValor(), 18.4003280886, 0.0001));
    assert(comparacaoValor(Q3.getValor(), 77.1143180419, 0.0001));
    assert(comparacaoValor(Q4.getValor(), 56.1728134280, 0.0001));
    assert(comparacaoValor(Q5.getValor(), 16.4612436467, 0.0001));
}