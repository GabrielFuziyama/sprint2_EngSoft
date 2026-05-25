/**
 * @file system.h
 * @brief Definição da classe System que representa os estoques (Stocks) do simulador.
 * @author Vítor de Sousa Costa Lopes e Gabriel Carneiro Gama Fuziyama
 * @date 2026
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

/**
 * @class System
 * @brief Representa uma unidade de acúmulo de estado (estoque) com um valor contínuo dentro do modelo de simulação.
 */
class System
{
private:
    std::string nome; /**< Identificador textual único do estoque. */
    double valor;     /**< Quantidade corrente de energia ou matéria acumulada no sistema. */

public:
    /**
     * @brief Construtor padrão da classe System.
     * Inicializa o estoque com nome vazio e valor zero.
     */
    System();

    /**
     * @brief Construtor com parâmetros da classe System.
     * @param nome Nome para identificação do estoque.
     * @param valor Volume inicial contínuo de estado do estoque.
     */
    System(const std::string &nome, double valor);

    /**
     * @brief Recupera o nome do sistema.
     * @return std::string Nome atual do sistema.
     */
    std::string getNome() const;

    /**
     * @brief Modifica o nome do sistema.
     * @param nome Novo nome a ser atribuído ao sistema.
     */
    void setNome(const std::string &nome);

    /**
     * @brief Recupera o valor (saldo) atual do estoque.
     * @return double O valor numérico acumulado.
     */
    double getValor() const;

    /**
     * @brief Define/sobrescreve diretamente o valor corrente do estoque.
     * @param valor Novo montante contínuo a ser injetado.
     */
    void setValor(double valor);

    /**
     * @brief Incrementa (soma) um montante ao valor atual do estoque.
     * @param valor Quantidade a ser adicionada.
     */
    void addValor(double valor);

    /**
     * @brief Decrementa (subtrai) um montante do valor atual do estoque.
     * @param valor Quantidade a ser removida.
     */
    void removeValor(double valor);
};

#endif