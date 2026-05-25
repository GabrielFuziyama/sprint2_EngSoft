#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System
{
private:
    std::string name;
    double value;

public:
    System();
    System(const std::string &name, double valor);

    std::string getName() const;
    void setName(const std::string &name);

    double getValue() const;
    void setValue(double valor);

    void addValue(double valor);
    void removeValue(double valor);
};

#endif