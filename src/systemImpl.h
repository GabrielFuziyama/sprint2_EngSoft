#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "system.h"

class SystemImpl : public System {
protected:
    std::string name;
    double value;
public:
    SystemImpl();
    SystemImpl(std::string name, double value);
    virtual ~SystemImpl();
    
    void setValue(double value);
    double getValue() const;
    void setName(std::string name);
    std::string getName() const;

    // Construtor de cópia e operador de atribuição (Forma Canônica)
    SystemImpl(const SystemImpl& other);
    SystemImpl& operator=(const SystemImpl& other);
};

#endif