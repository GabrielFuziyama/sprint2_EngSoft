#include "modelImpl.h"

ModelImpl::ModelImpl() : name("") {}
ModelImpl::ModelImpl(std::string name) : name(name) {}
ModelImpl::~ModelImpl() {
    // Apenas limpa os contêineres de ponteiros
    systems.clear();
    flows.clear();
}

void ModelImpl::add(System* sys) { systems.push_back(sys); }
void ModelImpl::add(Flow* flow) { flows.push_back(flow); }
void ModelImpl::setName(std::string name) { this->name = name; }
std::string ModelImpl::getName() const { return this->name; }

Model::systemIterator ModelImpl::beginSystems() { return systems.begin(); }
Model::systemIterator ModelImpl::endSystems() { return systems.end(); }
Model::flowIterator ModelImpl::beginFlows() { return flows.begin(); }
Model::flowIterator ModelImpl::endFlows() { return flows.end(); }

void ModelImpl::run(int start, int end, int step) {
    std::vector<double> results;
    for (int t = start; t < end; t += step) {
        results.clear();
        
        // Fase 1: Cálculo atômico isolado de todos os fluxos
        for (auto it = flows.begin(); it != flows.end(); ++it) {
            results.push_back((*it)->execute());
        }
        
        // Fase 2: Atualização síncrona dos estoques
        int i = 0;
        for (auto it = flows.begin(); it != flows.end(); ++it) {
            System* src = (*it)->getSource();
            System* tgt = (*it)->getTarget();
            if (src != nullptr) src->setValue(src->getValue() - results[i]);
            if (tgt != nullptr) tgt->setValue(tgt->getValue() + results[i]);
            i++;
        }
    }
}