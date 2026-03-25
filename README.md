# ROCK the SHOP 🎸👕

**ROCK the SHOP** este o aplicație consolă dezvoltată în C++ (folosind concepte de Programare Orientată pe Obiecte) pentru gestionarea unui magazin de muzică și vestimentație. Aplicația permite administrarea angajaților, a stocului de produse, procesarea comenzilor și generarea de rapoarte detaliate.

## 🌟 Funcționalități Principale

Aplicația oferă un meniu interactiv (CLI) structurat pe 4 categorii principale:

1. **Gestionare Angajați** 👥
   - Adăugare, ștergere și actualizare detalii angajați.
   - Afișarea tuturor angajaților sau căutarea după ID.
   - Tipuri de angajați suportați: *Manager*, *Operator*, *Asistent*.

2. **Gestionare Produse** 📦
   - Adăugare, stergere și actualizare stoc produse.
   - Afișarea tuturor produselor din stoc sau căutarea unui produs specific după cod.
   - Tipuri de produse: *Haine*, *Discuri* (normale) și *Discuri Vintage*.

3. **Procesare Comenzi** 🛒
   - Preluarea comenzilor plasate de clienți și asignarea lor către operatorii magazinului sau plasarea în coada de așteptare.

4. **Generare Rapoarte (CSV)** 📊
   - Exportarea datelor în format CSV pentru analiză:
     - Angajatul cu cele mai multe comenzi procesate.
     - Top 3 operatori cu cele mai valoroase comenzi.
     - Top 3 angajați cu cele mai mari salarii.

## 🛠️ Concepte OOP Utilizate

Aplicația folosește pe scară largă principii moderne de dezvoltare software (OOP):
- **Încapsulare**: Datele claselor sunt protejate.
- **Moștenire**: 
  - `Angajat` este baza pentru `Manager`, `Operator`, `Asistent`.
  - `Produs` este baza pentru `Haine`, `Disc`, `DiscVintage` (care la rândul său extinde clasa `Disc`).
- **Polimorfism**: Apeluri de funcții virtuale, permitând lucrul cu pointeri la clasele de bază pentru colecțiile de obiecte.
- **Tratarea Excepțiilor**: Gestionarea erorilor (blocuri `try-catch`) la instantierea obiectelor.
- **STL (Standard Template Library)**: Folosirea intensă a containerelor `std::vector`, `std::map` și `std::queue`.

## 🚀 Cum se rulează

### Cerințe:
- Un compilator C++ (suport minim C++11/C++14).
- [CMake](https://cmake.org/) (proiectul folosește `CMakeLists.txt` pentru build).

### Instrucțiuni (din terminal):
1. Clonează acest repository (sau copiază fișierele local).
2. Creează un folder pentru build:
   ```bash
   mkdir build
   cd build
   ```
3. Generează fișierele de configurare CMake și compilează:
   ```bash
   cmake ..
   cmake --build .
   ```
4. Rulează executabilul generat (ex. `./ROCK_the_SHOP` sau `ROCK_the_SHOP.exe` pe Windows).

> **Notă:** Asigură-te că fișierele de date inițiale (`FisierAngajati.txt`, `FisierProduse.txt`, `FisierComenzi.txt`) au calea configurată corect în `main.cpp` (actualmente setate pe directoare absolute) pentru o încărcare reușită a bazei de date de pornire.

## 📂 Structura Proiectului

* `main.cpp` - Punctul de intrare al aplicației și definirea meniului interactiv.
* `store.h` / `store.cpp` - Clasa principală `Store` care încapsulează logica, listele (vector/map/queue) și metodele pentru toate operațiunile magazinului.
* *Afișarea și ierarhia modelelor:* fișiere `*.h` și `*.cpp` delimitate logic (angajati, comenzi, produse, discuri, haine etc.).
* `Documentatie_POO.DOCX` - Documentația originală și detaliată a aplicației (în limba Română).
