#include "exponentialFlow.h"

ExponentialFlow::ExponentialFlow() : FlowImpl() {}
ExponentialFlow::ExponentialFlow(std::string name, System* source, System* target) : FlowImpl(name, source, target) {}
ExponentialFlow::~ExponentialFlow() {}

double ExponentialFlow::execute() {
    if (getSource() != nullptr) {
        return getSource()->getValue() * 0.01; // 1% do valor do sistema de origem
    }
    return 0.0;
}