#include "store.h"
#include <fstream>
#include <algorithm>

#include "asistent.h"
#include "disc.h"
#include "disc_vintage.h"
#include "haine.h"
#include "manager.h"

void Store::citireAngajati(const string &angajatiFile) {
    ifstream f(angajatiFile);
    if (!f.is_open()) {
        cerr << "File " << angajatiFile << " could not be opened" << endl;
        return;
    }
    string tip, nume, prenume, cnp;
    int zi, luna, an;
    while (f>>tip>>nume>>prenume>>cnp>>zi>>luna>>an) {
        try {
            if (tip == "Manager") {
                angajati.push_back(new Manager(nume, prenume, cnp, {zi,luna,an}));
            }
            else if (tip == "Operator") {
                Operator* op = new Operator(nume, prenume, cnp, {zi,luna,an});
                angajati.push_back(op);
                addOperator(op);
            }
            else if (tip == "Asistent") {
                angajati.push_back(new Asistent(nume, prenume, cnp, {zi,luna,an}));
            }
            else {
                cerr << "Tip de angajat necunoscut: " << tip << endl;
            }
        }catch(const exception &e) {
            cerr <<"Eroare la citirea angajatului: "<< e.what() << endl;
        }
    }
    f.close();
    cout<< "Angajatii au fost cititi din fisier."<<endl;
}

void Store::citireProduse(const string &produseFile) {
    ifstream f(produseFile);
    if (!f.is_open()) {
        cerr << "File " << produseFile << " could not be opened" << endl;
        return;
    }
    string tip, denumire, culoare, marca, casaDiscuri, trupa, album;
    int cod, nrProduse, zi, luna , an, raritate;
    double pret;
    bool mint;
    while (f>>tip) {
        try {
            if (tip == "Haine") {
                f>>cod>>denumire>>nrProduse>>pret>>culoare>>marca;
                produse.push_back(new Haine(cod, denumire, nrProduse, pret, culoare, marca));
            }
            else if (tip == "Disc") {
                f>>cod>>denumire>>nrProduse>>pret>>casaDiscuri>>zi>>luna>>an>>trupa>>album;
                produse.push_back(new Disc(cod, denumire, nrProduse, pret, casaDiscuri, {zi,luna,an}, trupa, album));
            }
            else if (tip == "DiscVintage") {
                f>>cod>>denumire>>nrProduse>>pret>>casaDiscuri>>zi>>luna>>an>>trupa>>album>>mint>>raritate;
                produse.push_back(new DiscVintage(cod, denumire, nrProduse, pret, casaDiscuri, {zi,luna,an}, trupa, album, mint, raritate));
            }
            else {
                cerr<<"Tip de produs necunoscut: "<< tip << endl;
            }
        }catch (const exception &e) {
            cerr<<"Eroare la citirea produsului: "<< e.what() << endl;
        }
    }
    f.close();
    cout<<"Produsele au fost citite din fisier."<<endl;
}

void Store::citireComenzi(const string &comenziFile) {
    ifstream f(comenziFile);
    if (!f.is_open()) {
        cerr << "File " << comenziFile << " could not be opened" << endl;
        return;
    }
    int an, luna, zi, cod, cantitate;
    while (f>>zi>>luna>>an) {
        vector<Produs*> coduriProduseComandate;
        vector<int> cantitati;
        while (f>>cod>>cantitate) {
            auto it = find_if(produse.begin(), produse.end(), [cod](Produs* p) {
                return p->getCod() == cod;
            });
            if (it != produse.end()) {
                coduriProduseComandate.push_back(*it);
                cantitati.push_back(cantitate);
            }
            else {
                cerr<<"Produsul cu codul: "<<cod<<" nu exista in stoc"<<endl;
            }
            if (f.peek() == '\n' || f.eof()) break;
        }
        if (!coduriProduseComandate.empty()) {
            try {
                Comanda c({zi,luna,an}, coduriProduseComandate, cantitati);
                if (c.esteValida()) {
                    addComanda(c);
                }else {
                    cerr<<"comanda cu id: "<<c.getId()<<"nu este valida (minim 100 lei, maxim 3 haine, maxim 5 discuri)"<<endl;
                }
            }
            catch (const exception &e) {
                cerr<<"eroare la cxrearea comenzii: "<<e.what()<<endl;
            }
        }
    }
    f.close();
    cout<<"Comenzile au fost citite din fisier."<<endl<<endl;
}


void Store::addComanda(const Comanda &c) {
    comenziAsteptare.push(c);
    cout<<"comanda cu id: "<<c.getId()<<" a fost adaugata in asteptare."<<endl;
}

void Store::addOperator(Operator* op) {
    operatori.push_back(op);
    comenziActive[op] = {}; // Inițializare fără comenzi active
    comenziPerOperator[op] = 0; // Inițializare fără comenzi procesate
}

void Store::addAngajati(Angajat *a) {
    angajati.push_back(a);
    cout<<"angajat adaugat: ";
    a->afisare(cout);
    cout<<endl;
}

void Store::addProduse(Produs *p) {
    produse.push_back(p);
    cout<<"produs adaugat: ";
    p->afisare(cout);
    cout<<endl;
}

void Store::delAngajati(int id) {
    auto it = find_if(angajati.begin(), angajati.end(),[&id](Angajat *a) {
        return a->getId() == id;
    });
    if (it != angajati.end()) {
        delete *it;
        angajati.erase(it);
        cout<<"angajatul cu id: "<<id<<" a fost sters"<<endl;
    }
    else {
        cout<<"angajatul cu id: "<<id<<" nu exista"<<endl;
    }
}

void Store::delProduse(int cod) {
    auto it = find_if(produse.begin(), produse.end(),[&cod](Produs *p) {
        return p->getCod() == cod;
    });
    if (it != produse.end()) {
        delete *it;
        produse.erase(it);
        cout<<"produsul cu cod: "<<cod<<" a fost sters"<<endl;
    }
    else {
        cout<<"produsul cu cod: "<<cod<<" nu exista"<<endl;
    }
}

void Store::updateAngajati(int id, string &numeNou) {
    auto it = find_if(angajati.begin(), angajati.end(),[&id](Angajat *a) {
        return a->getId() == id;
    });
    if (it != angajati.end()) {
        (*it)->numeNou(numeNou);
        cout<<"angajatul cu id: "<<id<<" a fost modificat"<<endl;
    }
    else {
        cout<<"angajatul cu id: "<<id<<" nu exista"<<endl;
    }
}

void Store::updateProduse(int cod, int produseAdaugate) {
    auto it = find_if(produse.begin(), produse.end(),[&cod](Produs *p) {
        return p->getCod() == cod;
    });
    if (it != produse.end()) {
        (*it)->adaugaProduse(produseAdaugate);
        cout<<"nr de produse cu cod: "<<cod<<" a fost actualizat"<<endl;
    }
    else {
        cout<<"produsul cu cod: "<<cod<<" nu exista"<<endl;
    }
}

void Store::afisareAngajati(ostream &dev) const {
    dev<<endl<<"TOTI ANGAJATII:"<<endl;
    for (const auto &a : angajati) {
        a->afisare(cout);
        dev<<endl;
    }
    dev<<endl;
}

void Store::afisareProduse(ostream &dev) const {
    dev<<endl<<"TOATE PRODUSELE:"<<endl;
    for (const auto &p : produse) {
        p->afisare(cout);
        dev<<endl;
    }
    dev<<endl;
}

void Store::afisareDateAngajat(int id, ostream &dev) const {
    auto it = find_if(angajati.begin(), angajati.end(),[&id](Angajat *a) {
        return a->getId() == id;
    });
    if (it != angajati.end()) {
        (*it)->afisare(dev);
    }
    else cout<<"Angajat cu ID-ul "<<id<<" nu exista in sistem."<<endl;
}

void Store::afisareDateProduse(int cod, ostream &dev) const {
    auto it = find_if(produse.begin(), produse.end(),[&cod](Produs *p) {
        return p->getCod() == cod;
    });
    if (it != produse.end()) {
        (*it)->afisare(dev);
    }
    else cout<<"Produsul cu codul: "<<cod<<" nu exista in sistem."<<endl;
}


void Store::procesareComenzi() {
    while (!comenziAsteptare.empty()) {
        Comanda c = comenziAsteptare.front();
        comenziAsteptare.pop();

        auto opLiber = min_element(operatori.begin(), operatori.end(), [this](Operator* a, Operator* b) {
            int nrComenziA = comenziActive[a].size();
            int nrComenziB = comenziActive[b].size();
            if (nrComenziA == nrComenziB) {
                return comenziPerOperator[a] < comenziPerOperator[b];
            }
            return nrComenziA < nrComenziB;
        });

        if (opLiber != operatori.end() && comenziActive[*opLiber].size() < 3) {
            Operator *op = *opLiber;
            comenziActive[op].push_back(c);
            comenziPerOperator[op]++;
            valComenziOperator[op] += c.valComanda();
            op->addValComenziProcese(c.valComanda());
            cout<<"Comanda cu id: "<<c.getId()<<" a fost asignata operatorului cu id: "<<op->getId();
            cout<<" care are: " <<comenziActive[op].size()<<" comenzi active."<<endl;
        }
        else {
            cout<<"Nu exista operatori disponibili."<<endl;
            comenziAsteptare.push(c);
            break;
        }
    }
}

void Store::raportAngajatMaxComenzi(const string &fisierRaportMaxComenzi) const{
    auto maxComenzi = max_element(operatori.begin(), operatori.end(), [this](Operator* a, Operator* b) {
        return comenziPerOperator.at(a) < comenziPerOperator.at(b);
    });
    ofstream f(fisierRaportMaxComenzi);
    if (!f.is_open()) {
        cerr<<"Nu s-a putut deschide fișierul pentru raport: "<<fisierRaportMaxComenzi<<endl;
        return;
    }
    f<<"Nume,Prenume,Numar Comenzi:"<<endl;
    if (maxComenzi != operatori.end()) {
        f<<(*maxComenzi)->getNume()<<","<<(*maxComenzi)->getPrenume()<<","<< comenziPerOperator.at(*maxComenzi)<<endl;
    } else {
        f<<"Nu există comenzi procesate încă."<<endl;
    }
    f.close();
    cout<<"Raportul a fost generat: "<<fisierRaportMaxComenzi<<endl;
}

void Store::raportTopOperatoriVal(const string& fisierRaportTopVal) const {
    vector<pair<Operator*, double>> valoriTotaleOperatori;
    for (const auto & pair : valComenziOperator) {
        const auto &op = pair.first;
        const auto &val = pair.second;
        valoriTotaleOperatori.emplace_back(op, val);
    }
    sort(valoriTotaleOperatori.begin(), valoriTotaleOperatori.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    ofstream file(fisierRaportTopVal);
    if (!file.is_open()) {
        cerr << "Nu s-a putut deschide fișierul pentru raport: " << fisierRaportTopVal << endl;
        return;
    }
    file << "Nume,Prenume,Valoare Totala Comenzi\n";
    for (int i = 0; i < 3 && i < valoriTotaleOperatori.size(); ++i) {
        file << valoriTotaleOperatori[i].first->getNume() << ","
             << valoriTotaleOperatori[i].first->getPrenume() << ","
             << valoriTotaleOperatori[i].second << "\n";
    }
    file.close();
    cout << "Raportul a fost generat: " << fisierRaportTopVal << endl;
}

void Store::raportTopOperatoriSalarii(const string &fisierRaportTopSal) const {
    vector<Angajat*> angajatiOrdonati = angajati;
    sort(angajatiOrdonati.begin(), angajatiOrdonati.end(), [](Angajat* a, Angajat* b) {
        return a->salariu() > b->salariu();
    });
    ofstream f(fisierRaportTopSal);
    if (!f.is_open()) {
        cerr << "Nu s-a putut deschide fișierul pentru raport: " << fisierRaportTopSal << endl;
        return;
    }
    f << "Nume,Prenume,Salariu\n";
    for (int i = 0; i < 3 && i < angajatiOrdonati.size(); ++i) {
        f << angajatiOrdonati[i]->getNume() << ","
             << angajatiOrdonati[i]->getPrenume() << ","
             << angajatiOrdonati[i]->salariu() << "\n";
    }
    f.close();
    cout << "Raportul a fost generat: " << fisierRaportTopSal << endl;
}

