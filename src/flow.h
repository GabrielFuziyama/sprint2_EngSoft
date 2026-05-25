/**
 * @file flow.h
 * @brief Definição da classe abstrata base Flow que gerencia as taxas de transferência.
 * @author Vítor de Sousa Costa Lopes e Gabriel Carneiro Gama Fuziyama
 * @date 2026
 */

#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

/**
 * @class Flow
 * @brief Classe abstrata (Interface) responsável por interligar os estoques (System) e calcular as taxas de variação.
 */
class Flow
{
protected:
    std::string nome;    /**< Nome identificador do fluxo de simulação. */
    System *origem;   /**< Ponteiro para o sistema estoque de origem (Source). */
    System *destino;   /**< Ponteiro para o sistema estoque de destino (Target). */

public:
    /**
     * @brief Construtor padrão da classe Flow.
     * Inicializa os ponteiros de conexão como nulos.
     */
    Flow();

    /**
     * @brief Construtor com parâmetros para amarração completa do fluxo.
     * @param nome Identificador do fluxo.
     * @param origem Endereço do estoque de saída.
     * @param destino Endereço do estoque de entrada.
     */
    Flow(const std::string &nome, System *origem, System *destino);

    /**
     * @brief Destrutor virtual da classe Flow.
     * Crucial para habilitar a liberação correta de memória das subclasses pelo polimorfismo.
     */
    virtual ~Flow();

    /**
     * @brief Recupera o nome do fluxo.
     * @return std::string Nome corrente do fluxo.
     */
    std::string getNome() const;

    /**
     * @brief Atualiza o nome do fluxo.
     * @param nome Novo nome identificador.
     */
    void setNome(const std::string &nome);

    /**
     * @brief Recupera o endereço de memória do sistema de origem.
     * @return System* Ponteiro para a origem vinculada.
     */
    System *getOrigem() const;

    /**
     * @brief Associa um sistema de armazenamento como origem do fluxo.
     * @param origem Ponteiro para o estoque de saída.
     */
    void setOrigem(System *origem);

    /**
     * @brief Recupera o endereço de memória do sistema de destino.
     * @return System* Ponteiro para o destino vinculado.
     */
    System *getDestino() const;

    /**
     * @brief Associa um sistema de armazenamento como destino do fluxo.
     * @param destino Ponteiro para o estoque de entrada.
     */
    void setDestino(System *destino);

    /**
     * @brief Método virtual puro que define a equação de transferência do fluxo.
     * Deve ser implementado por cada dinâmica concreta (exponencial, logística, etc.).
     * @return double O resultado numérico calculado da taxa de variação.
     */
    virtual double execute() = 0;
};

#endif