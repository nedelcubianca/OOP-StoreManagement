#include <iostream>
#include <fstream>
#include <cstring>
#include "Produs.h"
#include "Client.h"
#include "Comanda.h"

using namespace std;

bool isFileEmpty(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary | std::ios::ate);
    if (!file)
        std::cerr << "Eroare la deschiderea fisierului!\n";


    return file.tellg() == 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        cerr << "Utilizare: " << argv[0] << " <produse.txt> <clienti.txt>" << endl;

    if (isFileEmpty(argv[1]))
        std::cout << "Fisierul produse.txt este gol.\n";

    if (isFileEmpty(argv[2]))
        std::cout << "Fisierul clienti.txt este gol.\n";


    ifstream f1;
    f1.open(argv[1]);
    if (!f1)
        cerr << "Eroare la deschiderea fisierului produse.txt" << endl;

    int numarProduse;
    f1 >> numarProduse;
    if (f1.fail() || numarProduse <= 0)
        cerr << "Eroare la citirea numarului de produse" << endl;

    cout << "Numar produse: " << numarProduse << endl;
    f1.ignore();
    Produs* produse = new Produs[numarProduse];
    for (int i = 0; i < numarProduse; ++i)
    {
        char denumire[50];
        float pret;
        int cantitate;
        f1 >> denumire >> pret >> cantitate;
        if (f1.fail())
        {
            cerr << "Eroare la citirea produsului la pozitia " << i << endl;
            f1.clear();
            f1.ignore(10000, '\n');
            continue;
        }
        cout << denumire << " " << pret << " " << cantitate << endl;
        produse[i] = Produs(i, denumire, pret, cantitate);
    }
    f1.close();

    ifstream f2;
    f2.open(argv[2]);
    if (!f2)
    {
        cerr << "Eroare la deschiderea fisierului clienti.txt" << endl;
        delete[] produse;
    }

    int numarClienti;
    f2 >> numarClienti;
    if (f2.fail()  && isFileEmpty(argv[2])==1)
    {
        cerr << "Eroare la citirea numarului de clienti!" << endl;
        delete[] produse;

    }

    cout << "Numar clienti: " << numarClienti << endl;
    f2.ignore(10000, '\n');
    Client* clienti = new Client[numarClienti];
    for (int i = 0; i < numarClienti; i++)
    {
        char nume[60];
        f2.getline(nume, 60);
        if (f2.fail())
        {
            cerr << "Eroare la citirea numelui clientului la pozitia " << i << endl;
            f2.clear();
            f2.ignore(10000, '\n');
            continue;
        }
        cout << nume << endl;

        int zi, luna, an, nrProduseComanda;
        f2 >> zi >> luna >> an >> nrProduseComanda;
        if (f2.fail() || nrProduseComanda <= 0)
        {
            cerr << "Eroare la citirea datei sau numarului de produse pentru clientul " << nume << endl;
            f2.clear();
            f2.ignore(10000, '\n');
            continue;
        }
        cout << "Data comenzii: " << zi << " " << luna << " " << an << " " << nrProduseComanda << endl;
        f2.ignore(10000, '\n');

        Comanda comanda(i, zi, luna, an);
        for (int j = 0; j < nrProduseComanda; j++)
        {
            char denumireProdus[50];
            f2 >> denumireProdus;
            int cantitateProdus;
            f2 >> cantitateProdus;
            cout << denumireProdus << " " << cantitateProdus << endl;

            if (f2.fail())
            {
                cerr << "Eroare la citirea produsului pentru clientul " << nume << endl;
                f2.clear();
                f2.ignore(10000, '\n');
                continue;
            }
            f2.ignore();
            for (int k = 0; k < numarProduse; k++)
            {
                if (strcmp(produse[k].getDenumire(), denumireProdus) == 0)
                {
                    if (produse[k].getCantitate() >= cantitateProdus)
                    {
                        produse[k].setCantitate(produse[k].getCantitate() - cantitateProdus);
                        Produs produsComandat = produse[k];
                        produsComandat.setCantitate(cantitateProdus);
                        comanda.adaugaProdus(produsComandat);
                    }
                    else
                    {
                        cerr << "Stoc insuficient pentru produsul " << denumireProdus << endl;
                    }
                    break;
                }
            }
        }
        clienti[i] = Client(nume);
        clienti[i].setComanda(comanda);
    }
    f2.close();

    ofstream g1;
    g1.open("output_comenzi.txt");

    if (!g1)
        cerr << "Eroare la deschiderea fisierului output_comenzi.txt" << endl;

        for (int i = 0; i < numarClienti; i++)
        {
            g1 << "Nume: " << clienti[i].getNume() << endl;
            cout<< "Nume: " << clienti[i].getNume() << endl;
            const Comanda& comanda = clienti[i].getComanda();
            int zi, luna, an;
            comanda.getData(zi, luna, an);
            g1 << "Comanda ID: " << i << endl;
            cout << "Comanda ID: " << i << endl;
            g1 << "Data comenzii: " << zi << "/" << luna << "/" << an << endl;
            cout << "Data comenzii: " << zi << "/" << luna << "/" << an << endl;
            g1 << "Produse comandate:" << endl;
            cout << "Produse comandate:" << endl;
            const Produs* produseComandate = comanda.getProduse();
            float total = 0.0f;
            for (int j = 0; j < comanda.getNrProduse(); j++)
            {
                int  cant = produseComandate[j].getCantitate();
                char den[50];
                strcpy(den, produseComandate[j].getDenumire());
                float pret = produseComandate[j].getPret();
                g1 << cant << " X " << den << " (" << pret << ")" << endl;
                cout << cant << " X " << den << " (" << pret << ")" << endl;
                total += cant * pret;
            }
            g1 << "Total comanda: " << total << " RON" << endl ;
            cout << "Total comanda: " << total << " RON" << endl ;
            g1 << "\n" << endl;
        }
        g1.close();
        ofstream g2("output_stoc_ramas.txt");
        if (!g2)
            cerr << "Eroare la deschiderea fisierului output_stoc_ramas.txt" << endl;

        g2 << "Stoc ramas" << endl;
        cout << "Stoc ramas" << endl;
        for (int i = 0; i < numarProduse; i++)
        {
            g2 << i << ". " << produse[i].getDenumire() << ": " << produse[i].getCantitate() << ", Pret: " << produse[i].getPret() << endl;
            cout<< i << ". " << produse[i].getDenumire() << ": " << produse[i].getCantitate() << ", Pret: " << produse[i].getPret() << endl;
        }

    g2.close();
    delete[] produse;
    delete[] clienti;
    return 0;
}
