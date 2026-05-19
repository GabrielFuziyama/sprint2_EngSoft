#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow
{
protected:
    std::string nome;
    System *origem;
    System *destino;

public:
    Flow();
    Flow(const std::string &nome, System *origem, System *destino);
    virtual ~Flow();

    std::string getNome() const;
    void setNome(const std::string &nome);

    System *getOrigem() const;
    void setOrigem(System *origem);

    System *getDestino() const;
    void setDestino(System *destino);

    virtual double execute() = 0;
};

#endif
