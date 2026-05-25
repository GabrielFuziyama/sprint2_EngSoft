#include "system.h"

System::System()
{
    this->name = "";
    this->value = 0.0;
}

System::System(const std::string &name, double value)
{
    this->name = name;
    this->value = value;
}

std::string System::getName()
{
    return this->name;
}

void System::setName(const std::string &name)
{
    this->name = name;
}

double System::getValue() const
{
    return this->value;
}

void System::setValue(double value)
{
    this->value = value;
}

void System::addValue(double value)
{
    this->value += value;
}

void System::removeValue(double value)
{
    this->value -= value;
}
