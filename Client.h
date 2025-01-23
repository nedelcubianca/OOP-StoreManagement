#pragma once
#include "Comanda.h"

class Client {
private:
    char* nume;  // Numele clientului
    Comanda comanda; // Comanda clientului

public:
    Client(const char* nume = nullptr);
    Client(const Client& other);
    Client& operator=(const Client& other);
    ~Client();
    const char* getNume() const;
    void setComanda(const Comanda& comanda);
    const Comanda& getComanda() const;
};


