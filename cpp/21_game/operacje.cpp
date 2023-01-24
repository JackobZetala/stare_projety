#include "funkcje.h"
#include <iostream>

using namespace std;

void Gracz::dodaj_gracza(){
    cout<<"Podaj nazwe gracza: ";
    cin>>nick;
    monety=2000;
}
void Gracz::pokaz_gracza(){
    cout<<"Gracz: "<<nick<<"\t"<<"Monet: "<<monety<<endl;

}
void Gracz::odejmnij_zetony(int ile){
    monety=monety-ile;
}
void Gracz::dodaj_zetony(int ile){
    monety=monety+ile;
}
void Gracz::pokaz_rozb_gracza(){
    cout<<"Gracz: "<<nick<<"\t"<<"Monet: "<<monety<<"\t"<<"Suma oczek: "<<oczka<<endl;
}
void Gracz::start(){
    oczka=0;
}
void Gracz::wczytaj(){
    fstream plik;
    string linia;
    plik.open("save.txt",ios::in);
    if(plik.good()==true){

        }
    else
        cout<<"Brak zapisu";
    plik.close();
}
