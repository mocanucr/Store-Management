#ifndef STORE_H
#define STORE_H

#include "comanda.h"
#include "operator.h"
#include <queue>
#include <map>


#include "angajat.h"

class Store {
protected:
    vector<Operator*> operatori;
    map<Operator*, vector<Comanda>> comenziActive;
    map<Operator*, int> comenziPerOperator;
    map<Operator*, double> valComenziOperator;
    queue<Comanda> comenziAsteptare;

    vector<Angajat*> angajati;
    vector<Produs*> produse;
public:
    void citireAngajati(const string&);
    void citireProduse(const string&);
    void citireComenzi(const string&);

    void addComanda(const Comanda&);
    void addOperator(Operator*);
    void addAngajati(Angajat*);
    void addProduse(Produs*);

    void delAngajati(int);
    void delProduse(int);

    void updateAngajati(int, string&);
    void updateProduse(int, int);

    void procesareComenzi();

    void afisareAngajati(ostream&) const;
    void afisareProduse(ostream&) const;

    void afisareDateAngajat(int, ostream&) const;
    void afisareDateProduse(int, ostream&) const;

    void raportAngajatMaxComenzi(const string&) const;
    void raportTopOperatoriVal(const string&) const;
    void raportTopOperatoriSalarii(const string&) const;

};

#endif //STORE_H
