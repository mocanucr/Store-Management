#ifndef ASISTENT_H
#define ASISTENT_H

#include "angajat.h"

class Asistent:public Angajat{

public:
    Asistent();
    Asistent(string, string, string, Data);
    void afisare(ostream &) const;
    double salariu() const;
    void afisareSalariu(ostream &) const;
};

#endif //ASISTENT_H
