#pragma once
#include "Produs.h"

class Comanda {
private:
    int id;
    int zi, luna, an;             // Data comenzii
    int nrProduse;                // Numarul total de produse din comanda
    Produs* produse;              // Vector alocat dinamic pentru produsele din comanda

public:
    Comanda(int id = 0, int zi = 1, int luna = 1, int an = 2000);
    Comanda(const Comanda& other);
    Comanda& operator=(const Comanda& other);
    ~Comanda();
    void adaugaProdus(const Produs& produs);
    void getData(int& zi, int& luna, int& an) const;
    int getNrProduse() const;
    const Produs* getProduse() const;
};


