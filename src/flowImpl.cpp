#include "flowImpl.h"

FlowImpl::FlowImpl() : name(""), source(nullptr), target(nullptr) {}
FlowImpl::FlowImpl(std::string name, System* source, System* target) : name(name), source(source), target(target) {}
FlowImpl::~FlowImpl() {}

void FlowImpl::setSource(System* source) { this->source = source; }
System* FlowImpl::getSource() const { return this->source; }
void FlowImpl::setTarget(System* target) { this->target = target; }
System* FlowImpl::getTarget() const { return this->target; }
void FlowImpl::setName(std::string name) { this->name = name; }
std::string FlowImpl::getName() const { return this->name; }

FlowImpl::FlowImpl(const FlowImpl& other) {
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

FlowImpl& FlowImpl::operator=(const FlowImpl& other) {
    if (this == &other) return *this;
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
    return *this;
}