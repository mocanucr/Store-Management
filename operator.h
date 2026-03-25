#ifndef OPERATOR_H
#define OPERATOR_H

#include "angajat.h"

class Operator:public Angajat{
protected:
    double valComenziProcesate;
public:
    Operator();
    Operator(string, string, string, Data);
    void afisare(ostream &) const;
    double salariu() const;
    void addValComenziProcese(double);
    void afisareSalariu(ostream &) const;
};

#endif //OPERATOR_H
