/**
 * @file model.h
 * @brief Definição do contêiner central Model responsável por reger a simulação iterativa.
 * @author Vítor de Sousa Costa Lopes e Gabriel Carneiro Gama Fuziyama
 * @date 2026
 */

#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "system.h"
#include "flow.h"

/**
 * @class Model
 * @brief Gerencia e coordena o ciclo de vida dos estoques e fluxos, executando a simulação temporal atômica.
 */
class Model
{
private:
    std::vector<System*> sistema; /**< Coleção de ponteiros para os estoques agregados ao modelo. */
    std::vector<Flow*> flows;     /**< Coleção de ponteiros para as equações de fluxo agregadas ao modelo. */

public:
    /**
     * @brief Construtor padrão do motor de simulação Model.
     */
    Model();

    /**
     * @brief Adiciona e registra um estoque (System) ao escopo do modelo.
     * @param sistema Ponteiro para a instância do estoque a ser rastreada.
     */
    void add(System* sistema);

    /**
     * @brief Adiciona e registra uma equação de fluxo (Flow) ao escopo do modelo.
     * @param flow Ponteiro para a instância do fluxo a ser executada.
     */
    void add(Flow* flow);

    /**
     * @brief Recupera o vetor contendo todos os sistemas do modelo.
     * @return std::vector<System*> Vetor de ponteiros dos estoques.
     */
    std::vector<System*> getSistema() const;

    /**
     * @brief Recupera o vetor contendo todos os fluxos do modelo.
     * @return std::vector<Flow*> Vetor de ponteiros de fluxos.
     */
    std::vector<Flow*> getFlows() const;

    /**
     * @brief Realiza uma busca textual para localizar um estoque dentro do contêiner.
     * @param name Nome correspondente ao estoque procurado.
     * @return System* Endereço do estoque encontrado ou nulo caso não exista.
     */
    System* getSistema(const std::string& name) const;

    /**
     * @brief Dispara a simulação temporal iterativa dividida nas fases atômicas de cálculo e atualização.
     * @param start Tempo inteiro de largada da simulação (Ex: 0).
     * @param end Tempo inteiro limite para parada da simulação (Ex: 100).
     * @param step Intervalo discreto de passo temporal para cada ciclo (Ex: 1).
     */
    void run(int start, int end, int step);
};

#endif