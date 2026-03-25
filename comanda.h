#ifndef COMANDA_H
#define COMANDA_H

#include "data.h"
#include "produs.h"
#include <vector>

class Comanda {
protected:
    int id;
    Data dataComanda;
    int durataSol;
    vector<Produs*> produse;
    vector<int> cantitai;
    static int nr;
    double val;
public:
    Comanda();
    Comanda(Data, vector<Produs*>&, vector<int>&);
    double valComanda() const;
    bool esteValida() const;
    int getDurataSol() const {return durataSol;}
    int getId() const {return id;}
    double getValComanda() const {return val;}
    void afisare(ostream&) const;
    int calcDurataSol();
};

#endif //COMANDA_H
