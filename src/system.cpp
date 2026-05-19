#include "system.h"

System::System()
{
    this->nome = "";
    this->valor = 0.0;
}

System::System(const std::string &nome, double valor)
{
    this->nome = nome;
    this->valor = valor;
}

std::string System::getNome() const
{
    return this->nome;
}

void System::setNome(const std::string &nome)
{
    this->nome = nome;
}

double System::getValor() const
{
    return this->valor;
}

void System::setValor(double valor)
{
    this->valor = valor;
}

void System::addValor(double valor)
{
    this->valor += valor;
}

void System::removeValor(double valor)
{
    this->valor -= valor;
}
