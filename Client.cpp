#include "Client.h"
#include <iostream>
#include <cstring>

Client::Client(const char* nume)
{
    if (nume)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }
    else
    {
        this->nume = nullptr;
    }
}

Client::Client(const Client& other)
{

    if (other.nume != nullptr)
    {
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
    }
    else
    {
        nume = nullptr;
    }

    comanda = other.comanda;
}

Client& Client::operator=(const Client& other)
{

    if (this == &other)
        return *this;

    if (nume != nullptr)
        delete[] nume;

    if (other.nume != nullptr)
    {
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
    }
    else
    {
        nume = nullptr;
    }
    comanda = other.comanda;
    return *this;
}


Client::~Client()
{
    delete[] nume;
}

const char* Client::getNume() const
{
    return nume;
}

void Client::setComanda(const Comanda& comanda)
{
    this->comanda = comanda;
}

const Comanda& Client::getComanda() const
{
    return comanda;
}

