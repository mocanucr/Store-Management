#include "asistent.h"
#include "disc.h"
#include "disc_vintage.h"
#include "haine.h"
#include "manager.h"
#include "store.h"

int main()
{
    Store magazin;

    magazin.citireAngajati("C:/Users/Cristi/OneDrive/Desktop/ROCK_THE_SHOP/FisierAngajati.txt");
    magazin.citireProduse("C:/Users/Cristi/OneDrive/Desktop/ROCK_THE_SHOP/FisierProduse.txt");
    magazin.citireComenzi("C:/Users/Cristi/OneDrive/Desktop/ROCK_THE_SHOP/FisierComenzi.txt");

    int option;
    do {
        cout << "\n--- Meniu Magazin ---\n";
        cout << "1. Gestionare angajati\n";
        cout << "2. Gestionare produse\n";
        cout << "3. Procesare comenzi\n";
        cout << "4. Generare rapoarte\n";
        cout << "0. Iesire\n";
        cout << "Alegeti o optiune: ";
        cin >> option;

        switch (option) {
            case 1: {
                int suboption;
                cout << "\n--- Gestionare Angajati ---\n";
                cout << "1. Adaugare angajat\n";
                cout << "2. Stergere angajat\n";
                cout << "3. Modificare angajat\n";
                cout << "4. Afisare angajati\n";
                cout << "5. Afisare angajat dupa id\n";
                cout << "0. Inapoi\n";
                cout << "Alegeti o optiune: ";
                cin >> suboption;
                switch (suboption) {
                    case 1: {
                        string nume, prenume, cnp;
                        int zi, luna , an, tip;
                        cout << "Alegeti tipul angajatului: 1-manager, 2-operator, 3-asistent: ";
                        cin >> tip;
                        cout << endl;
                        cout << "Introduceti nume, prenume, CNP: ";
                        cin >> nume >> prenume >> cnp;
                        cout << endl;
                        cout << "Introduceti data angajarii (zi luna an): ";
                        cin >> zi >> luna >> an;
                        cout << endl;
                        try {
                            Angajat *a = nullptr;
                            switch (tip) {
                                case 1:
                                    a = new Manager(nume, prenume, cnp, {zi, luna, an});
                                    break;
                                case 2:
                                    a = new Operator(nume, prenume, cnp, {zi, luna, an});
                                    break;
                                case 3:
                                    a = new Asistent(nume, prenume, cnp, {zi, luna, an});
                                    break;
                                default:
                                    cerr << "Tipul angajatului este invalid." << endl;
                                    break;
                            }
                            if (a != nullptr) {
                                magazin.addAngajati(a);
                            }
                        } catch (const exception &e) {
                            cerr << "Eroare: " << e.what() << endl;
                        }
                        break;
                    }
                    case 2: {
                        int id;
                        cout << "Introduceti ID-ul angajatului de sters: ";
                        cin >> id;
                        magazin.delAngajati(id);
                        break;
                    }
                    case 3: {
                        int id;
                        string numeNou;
                        cout << "Introduceti ID-ul angajatului si numele nou: ";
                        cin >> id >> numeNou;
                        magazin.updateAngajati(id, numeNou);
                        break;
                    }
                    case 4: {
                        magazin.afisareAngajati(cout);
                        break;
                    }
                    case 5: {
                        int id;
                        cout << "Introduceti ID-ul angajatului caruia vreti sa ii afisati datele: ";
                        cin >> id;
                        magazin.afisareDateAngajat(id, cout);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cerr << "Optiune invalida!" << endl;
                        break;
                }
                break;
            }
            case 2: {
                int suboption;
                cout << "\n--- Gestionare Produse ---\n";
                cout << "1. Adaugare produs\n";
                cout << "2. Stergere produs\n";
                cout << "3. Modificare produs\n";
                cout << "4. Afisare produse\n";
                cout << "5. Afisare produs dupa cod\n";
                cout << "0. Inapoi\n";
                cout << "Alegeti o optiune: ";
                cin >> suboption;
                switch (suboption) {
                    case 1: {
                        string denumire;
                        int cod, nrProduse, tip;
                        double pret;
                        cout << "Alegeti tipul produsului: 1-haina, 2-disc, 3-disc vintage: ";
                        cin >> tip;
                        cout << endl;
                        cout << "Introduceti codul, denumirea, numarul de produse si pretul: ";
                        cin >> cod >> denumire >> nrProduse >> pret;
                        Produs *p = nullptr;
                        switch (tip) {
                            case 1: {
                                string culoare, marca;
                                cout << "Introduceti culoarea si marca: ";
                                cin >> culoare >> marca;
                                p = new Haine(cod, denumire, nrProduse, pret, culoare, marca);
                                break;
                            }
                            case 2: {
                                string casaDiscuri, trupa, album;
                                int zi, luna, an;
                                cout << "Introduceti casa de discuri, data lansarii (zi luna an), trupa si album: ";
                                cin >> casaDiscuri >> zi >> luna >> an >> trupa >> album;
                                p = new Disc(cod, denumire, nrProduse, pret, casaDiscuri, {zi, luna, an}, trupa, album);
                                break;
                            }
                            case 3: {
                                string casaDiscuri, trupa, album;
                                int zi, luna, an, raritate;
                                bool mint;
                                cout << "Introduceti casa de discuri, data lansarii (zi luna an), trupa, album, mint (1/0) si raritate: ";
                                cin >> casaDiscuri >> zi >> luna >> an >> trupa >> album >> mint >> raritate;
                                p = new DiscVintage(cod, denumire, nrProduse, pret, casaDiscuri, {zi, luna, an}, trupa, album, mint, raritate);
                                break;
                            }
                            default:
                                cerr << "Tipul de produs este invalid." << endl;
                                break;
                        }
                        magazin.addProduse(p);
                        break;
                    }
                    case 2: {
                        int cod;
                        cout << "Introduceti codul produsului de sters: ";
                        cin >> cod;
                        magazin.delProduse(cod);
                        break;
                    }
                    case 3: {
                        int cod, nrProduseNoi;
                        cout << "Introduceti codul produsului si numarul nou de produse adaugate: ";
                        cin >> cod >> nrProduseNoi;
                        magazin.updateProduse(cod, nrProduseNoi);
                        break;
                    }
                    case 4: {
                        magazin.afisareProduse(cout);
                        break;
                    }
                    case 5: {
                        int cod;
                        cout << "Introduceti codul produsului caruia vreti sa ii afisati datele: ";
                        cin >> cod;
                        magazin.afisareDateProduse(cod, cout);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default:
                        cerr << "Optiune invalida!\n";
                        break;
                }
                break;
            }
            case 3: {
                magazin.procesareComenzi();
                break;
            }
            case 4: {
                int suboptiune;
                cout << "\n--- Generare Rapoarte ---\n";
                cout << "1. Angajatul cu cele mai multe comenzi procesate\n";
                cout << "2. Top 3 operatori cu cele mai valoroase comenzi\n";
                cout << "3. Top 3 angajati cu cele mai mari salarii\n";
                cout << "0. Inapoi\n";
                cout << "Alegeti o optiune: ";
                cin >> suboptiune;

                switch (suboptiune) {
                    case 1:
                        magazin.raportAngajatMaxComenzi("raport_angajat_max_comenzi.csv");
                        break;
                    case 2:
                        magazin.raportTopOperatoriVal("raport_top_operatori_valori.csv");
                        break;
                    case 3:
                        magazin.raportTopOperatoriSalarii("raport_top_angajati_salarii.csv");
                        break;
                    case 0:
                        break;
                    default:
                        cerr << "Optiune invalida!\n";
                        break;
                }
                break;
            }
            case 0:
                cout << "La revedere!\n";
                break;
            default:
                cerr << "Optiune invalida!\n";
                break;
        }
    } while (option != 0);

    return 0;
}
