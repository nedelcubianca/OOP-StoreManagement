#include "Produs.h"
#include <cstring>

Produs::Produs(int id, const char* denumire, float pret, int cantitate) {
    this->id = id;
    this->pret = pret;
    this->cantitate = cantitate;
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
}

Produs::Produs(const Produs& other) {
    id = other.id;
    pret = other.pret;
    cantitate = other.cantitate;
    if (other.denumire != nullptr) {
        denumire = new char[strlen(other.denumire) + 1];
        strcpy(denumire, other.denumire);
    } else {
        denumire = nullptr;
    }
}

Produs& Produs::operator=(const Produs& other) {
    if (this == &other) {
        return *this;
    }

    delete[] denumire;


    id = other.id;
    pret = other.pret;
    cantitate = other.cantitate;


    if (other.denumire != nullptr) {
        denumire = new char[strlen(other.denumire) + 1];
        strcpy(denumire, other.denumire);
    } else {
        denumire = nullptr;
    }
    return *this;
}

Produs::~Produs() {
    delete[] denumire;
}

int Produs::getId() const {
    return id;
}

const char* Produs::getDenumire() const {
    return denumire;
}

float Produs::getPret() const {
    return pret;
}

int Produs::getCantitate() const {
    return cantitate;
}

void Produs::setCantitate(int cantitate) {
    this->cantitate = cantitate;
}

