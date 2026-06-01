#include "logisticalFlow.h"

LogisticalFlow::LogisticalFlow() : FlowImpl() {}
LogisticalFlow::LogisticalFlow(std::string name, System* source, System* target) : FlowImpl(name, source, target) {}
LogisticalFlow::~LogisticalFlow() {}

double LogisticalFlow::execute() {
    if (getTarget() != nullptr) {
        // Regra logística de saturação sustentada em 70
        return 0.01 * getTarget()->getValue() * (1.0 - (getTarget()->getValue() / 70.0));
    }
    return 0.0;
}