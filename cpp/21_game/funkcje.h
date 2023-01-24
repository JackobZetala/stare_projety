#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

class Gracz{
public:
    string nick;
    int monety;
    int oczka;
    int liczba_graczy1;

    void dodaj_zetony(int ile);
    void odejmnij_zetony(int ile);
    void dodaj_gracza();
    void pokaz_gracza();
    void pokaz_rozb_gracza();
    void start();
    void wczytaj();


};



#endif // FUNKCJE_H
