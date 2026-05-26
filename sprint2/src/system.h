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
    System(const std::string &name, double value);

    System(const System &other);
    virtual ~System();
    System &operator=(const System &other);

    std::string getName() const;
    void setName(const std::string &name);

    double getValue() const;
    void setValue(double value);

    void addValue(double value);
    void removeValue(double value);
};

#endif
