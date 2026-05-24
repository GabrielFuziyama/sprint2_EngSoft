#include "system.h"

System::System()
{
    this->name = "";
    this->valor = 0.0;
}

System::System(const std::string &name, double valor)
{
    this->name = name;
    this->valor = valor;
}

std::string System::getName() const
{
    return this->name;
}

void System::setName(const std::string &name)
{
    this->name = name;
}

double System::getValue() const
{
    return this->valor;
}

void System::setValue(double valor)
{
    this->valor = valor;
}

void System::addValue(double valor)
{
    this->valor += valor;
}

void System::removeValue(double valor)
{
    this->valor -= valor;
}
