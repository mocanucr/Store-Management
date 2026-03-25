#ifndef MANAGER_H
#define MANAGER_H

#include "angajat.h"

class Manager:public Angajat{

public:
    Manager();
    Manager(string, string, string, Data);
    void afisare(ostream &) const;
    double salariu() const;
    void afisareSalariu(ostream &) const;
};

#endif //MANAGER_H
