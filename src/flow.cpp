#include "flow.h"

Flow::Flow()
{
    this->nome = "";
    this->origem = 0;
    this->destino = 0;
}

Flow::Flow(const std::string &nome, System *origem, System *destino)
{
    this->nome = nome;
    this->origem = origem;
    this->destino = destino;
}

Flow::~Flow()
{
}

std::string Flow::getNome() const
{
    return this->nome;
}

void Flow::setNome(const std::string &nome)
{
    this->nome = nome;
}

System *Flow::getOrigem() const
{
    return this->origem;
}

void Flow::setOrigem(System *origem)
{
    this->origem = origem;
}

System *Flow::getDestino() const
{
    return this->destino;
}

void Flow::setDestino(System *destino)
{
    this->destino = destino;
}
