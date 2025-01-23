#include "Comanda.h"
#include <iostream>

Comanda::Comanda(int id, int zi, int luna, int an) {
    this->id = id;
    this->zi = zi;
    this->luna = luna;
    this->an = an;
    this->nrProduse = 0;
    this->produse = nullptr;
}

Comanda::Comanda(const Comanda& other)
{
     id = other.id;
    zi = other.zi;
    luna = other.luna;
    an = other.an;
    nrProduse = other.nrProduse;

    if (nrProduse > 0) {
        produse = new Produs[nrProduse];
        for (int i = 0; i < nrProduse; i++) {
            produse[i] = other.produse[i];
        }
    } else {
        produse = nullptr;
    }
}

Comanda& Comanda::operator=(const Comanda& other) {
   if (this == &other)
        return *this;

    if (produse != nullptr)
        delete[] produse;

    id = other.id;
    zi = other.zi;
    luna = other.luna;
    an = other.an;
    nrProduse = other.nrProduse;


    if (nrProduse > 0 && other.produse != nullptr) {
        produse = new Produs[nrProduse];
        for (int i = 0; i < nrProduse; i++) {
            produse[i] = other.produse[i];
        }
    } else {
        produse = nullptr;
    }


    return *this;
}

Comanda::~Comanda() {
    delete[] produse;
}

void Comanda::adaugaProdus(const Produs& produs) {
    Produs* temp = new Produs[nrProduse + 1];
    for (int i = 0; i < nrProduse; i++) {
        temp[i] = produse[i];
    }
    temp[nrProduse] = produs;
    delete[] produse;
    produse = temp;
    nrProduse++;
}

void Comanda::getData(int& zi, int& luna, int& an) const {
    zi = this->zi;
    luna = this->luna;
    an = this->an;
}

int Comanda::getNrProduse() const {
    return nrProduse;
}

const Produs* Comanda::getProduse() const {
    return produse;
}

