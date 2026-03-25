#ifndef PRODUS_H
#define PRODUS_H

#pragma once
#include <iostream>
#include <string>
#include "data.h"

using namespace std;

class Produs{
protected:
    int cod;
    string denumire;
    int nrProduse;
    double pretBaza;

public:
    Produs() = default;
    Produs(int, string, int, double);
    void adaugaProduse(int);
    int getCod() const;
    virtual void afisare(ostream &) const;
    virtual double pretFinal() const = 0;
    virtual bool esteHaina() const { return false; }
    virtual bool esteDisc() const { return false; }
    virtual bool esteDiscVintage() const { return false; }
    virtual int getTimpLivrare() const = 0;
    virtual int getTimpImpachetare() const = 0;
};

#endif //PRODUS_H
