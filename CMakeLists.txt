cmake_minimum_required(VERSION 3.30)
project(poo_lion)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        poo_lion
        main.cpp
        angajat.cpp
        angajat.h
        manager.cpp
        manager.h
        asistent.cpp
        asistent.h
        operator.cpp
        operator.h
        produs.cpp
        produs.h
        haine.cpp
        haine.h
        disc.cpp
        disc.h
        disc_vintage.cpp
        disc_vintage.h
        comanda.cpp
        comanda.h
        store.cpp
        store.h
        data.h
        FisierComenzi.txt
        FisierProduse.txt
        FisierAngajati.txt
)
