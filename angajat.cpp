#include "angajat.h"
#include <vector>

bool Angajat::validareCNP(string cnp){
    if(cnp.length() != 13)
        return false;
    for (char c : cnp) {
        if (!std::isdigit(c))
            return false;
    }
    vector<int> constanta = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    int s = 0;

    for (int i = 0; i < 12; ++i) {
        s += (cnp[i] - '0') * constanta[i];
    }

    int cifraControl = s % 11;
    if (cifraControl == 10)
        cifraControl = 1;

    if ((cnp[12] - '0') != cifraControl)
        return false;
    else return true;
}

int Angajat::nr = 65789; // random

Angajat::Angajat(string n, string p, string cnp, Data d)
{
    id = nr;
    nr++;

    if(n.length()<3 || n.length()>30)
        throw invalid_argument("numele nu este bun");
    else nume = n;

    if(p.length()<3 || p.length()>30)
        throw invalid_argument("prenumele nu este bun");
    else prenume = p;

    if(validareCNP(cnp))
        CNP = cnp;
    else throw invalid_argument("cnp invalid");

    int zi, luna, an;
    zi = (CNP[5] - '0') * 10 + (CNP[6] - '0');
    luna = (CNP[3] - '0') * 10 + (CNP[4] - '0');
    an = (CNP[1] - '0') * 10 + (CNP[2] - '0');
    if((CNP[0]-'0') == 5 || CNP[0]-'0' == 6) an +=2000;
    else if(CNP[0]-'0'==1 || CNP[0]-'0'==2) an +=1900;
    Data nastere = {zi, luna, an};


    int v = difAni(nastere);
    if(v < 18)
        throw invalid_argument("minor");

    data_angajarii = d;
    int dif = difAni(data_angajarii);
    if(dif < 0)
        throw invalid_argument("data angajarii nu este buna");
}

void Angajat::numeNou(string n){
    if(n.length()<3 || n.length()>30)
        throw invalid_argument("numele nu este bun");
    else nume = n;
}

void Angajat::afisare(ostream &dev) const{
    dev<<endl;
    dev<<id<<" "<<nume<<" "<<prenume<<" "<<CNP<<" ";
    dev<<data_angajarii.zi<<" "<<data_angajarii.luna<<" "<<data_angajarii.an<<" ";
    // return dev
}

double Angajat::salariu() const{
    double s = 3500;
    int vechime = difAni(data_angajarii);
    s += 100 * vechime;
    return s;
}