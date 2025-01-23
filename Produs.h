#pragma once

#include <iostream>
#include <cstring>

class Produs {
    int id;                  // Cod unic al produsului
    char* denumire;          // Denumirea produsului (șir de caractere)
    float pret;              // Prețul produsului
    int cantitate;           // Cantitatea pe stoc a produsului

public:
    Produs(int id = 0, const char* denumire = "", float pret = 0.0, int cantitate = 0);
    Produs(const Produs& other);
    Produs& operator=(const Produs& other);
    ~Produs();
    int getId() const;
    const char* getDenumire() const;
    float getPret() const;
    int getCantitate() const;
    void setCantitate(int cantitate);
};

