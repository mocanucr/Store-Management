#ifndef ANGAJAT_H
#define ANGAJAT_H

#pragma once
#include <iostream>
#include <string>
#include "data.h"

using namespace std;

class Angajat{
protected:
    int id;
    string nume;
    string prenume;
    string CNP;
    Data data_angajarii = {0, 0, 0};
    static int nr;

public:
    Angajat() = default;
    Angajat(string, string, string, Data);
    void numeNou(string);
    virtual void afisare(ostream &) const;
    virtual double salariu() const;
    virtual void afisareSalariu(ostream &) const = 0;
    bool validareCNP(string);
    int getId() const {return id;}
    string getNume() const {return nume;}
    string getPrenume() const {return prenume;}
};

#endif //ANGAJAT_H
