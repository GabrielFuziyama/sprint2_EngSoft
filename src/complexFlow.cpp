#include "complexFlow.h"

ComplexFlow::ComplexFlow() : FlowImpl() {}
ComplexFlow::ComplexFlow(std::string name, System* source, System* target) : FlowImpl(name, source, target) {}
ComplexFlow::~ComplexFlow() {}

double ComplexFlow::execute() {
    if (getSource() != nullptr) {
        return getSource()->getValue() * 0.01;
    }
    return 0.0;
}