#include "systemImpl.h"

SystemImpl::SystemImpl() : name(""), value(0.0) {}
SystemImpl::SystemImpl(std::string name, double value) : name(name), value(value) {}
SystemImpl::~SystemImpl() {}

void SystemImpl::setValue(double value) { this->value = value; }
double SystemImpl::getValue() const { return this->value; }
void SystemImpl::setName(std::string name) { this->name = name; }
std::string SystemImpl::getName() const { return this->name; }

SystemImpl::SystemImpl(const SystemImpl& other) {
    this->name = other.name;
    this->value = other.value;
}

SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->value = other.value;
    return *this;
}