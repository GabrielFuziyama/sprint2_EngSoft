#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System
{
private:
    std::string nome;
    double valor;

public:
    System();
    System(const std::string &nome, double valor);

    std::string getNome() const;
    void setNome(const std::string &nome);

    double getValor() const;
    void setValor(double valor);

    void addValor(double valor);
    void removeValor(double valor);
};

#endif
