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

System::System(const System &other)
{
    this->name = other.name;
    this->value = other.value;
}

System::~System()
{
}

System &System::operator=(const System &other)
{
    if (this == &other)
    {
        return *this;
    }

    this->name = other.name;
    this->value = other.value;

    return *this;
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
