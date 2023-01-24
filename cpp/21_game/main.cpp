#include <iostream>
#include "funkcje.h"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>


using namespace std;
int rzut_koscia();
int wybor();
void rozgrywka();

int main()
{
    srand(time(NULL));
    cout << "Witam w grze w kosci 21" << endl;
    char wybor1;
    for(;;){
    cout<<"MENU GLOWNE"<<endl;
    cout<<"____________"<<endl;
    cout<<"1.Graj"<<endl;
    cout<<"2.Wczytaj"<<endl;
    cout<<"3.Zakoncz"<<endl;
    cout<<"Wybierz: "<<endl;
    wybor1=getch();
    switch(wybor1)
    {
    case '1':
        system("cls");
        rozgrywka();
    break;
    case '2':
        cout<<"wczytuje"<<endl;
    break;
    case '3':
        exit(0);
    break;
    default: cout<<"Nie ma takiej opcji"<<endl;
    }
    getchar();getchar();
    system("cls");
    }

    return 0;
}






int rzut_koscia(){
    int x=0;
    x=rand()%6+1;
    cout<<"Wylosowano: "<<x<<endl;
    return x;
}

void rozgrywka(){
    string rozgrywka="tak";
    int liczba_graczy;
    cout << "Podaj liczbe uczestnikow: ";
    cin>>liczba_graczy;
    Gracz g[liczba_graczy];
    g[0].liczba_graczy1=liczba_graczy;

    for(int i=0;i<liczba_graczy;i++){
            g[i].dodaj_gracza();
        }
        system("cls");
        while(rozgrywka=="tak") {
        cout <<"Rozpoczynamy rozgrywke !!!"<<endl;
        cout <<"Z puli kazdego gracza zabieram po 500 monet i zaczynamy rzuty kostka"<<endl;

        for(int i=0;i<liczba_graczy;i++){
            g[i].start();
            g[i].odejmnij_zetony(500);
            g[i].pokaz_gracza();
            g[i].oczka+=rzut_koscia();
            g[i].oczka+=rzut_koscia();
            g[i].oczka+=rzut_koscia();
            g[i].pokaz_rozb_gracza();
            int wyb=wybor();
            for(int j=0;j<wyb;j++){
                g[i].oczka+=rzut_koscia();
            }
            if(g[i].oczka<21)
                g[i].pokaz_rozb_gracza();
            if(g[i].oczka>21){
                cout<<"Przegrales bo przekroczyles 21"<<endl;
                g[i].oczka=0;}
            if(g[i].oczka==21){
                cout<<"WOW udalo sie zdobyc 21";

            }
            getchar();getchar();
            system("cls");
        }
        int wynik=0;
        string imie;
        for(int i=0;i<liczba_graczy;i++){
            if(g[i].oczka>wynik){
                wynik=g[i].oczka;
                imie=g[i].nick;
            }
            else if(g[i].oczka==wynik){
                imie="remis";
            }
        }
        if(wynik==0)
            cout<<"Brak zwyciezcy"<<endl;
        else if(imie=="remis"){
            cout<<"Remis z wynikiem: "<<wynik<<endl;
            int zliczanie=0;
            for(int i=0;i<liczba_graczy;i++){
                if(g[i].oczka==wynik){
                    zliczanie++;
                }}
            int wygrana=(liczba_graczy*500)/zliczanie;
            for(int i=0;i<liczba_graczy;i++){
                if(g[i].oczka==wynik){
                    g[i].dodaj_zetony(wygrana);}}

        }
        else{
            cout<<"Wygral: "<<imie<<" z wynikiem "<<wynik<<" punktow. Gratulacje :D"<<endl;
            for(int i=0;i<liczba_graczy;i++){
                if(g[i].nick==imie){
                    int wygrana=liczba_graczy*500;
                    g[i].dodaj_zetony(wygrana);
        }}}
        for(int i=0;i<liczba_graczy;i++){
            if(g[i].monety==0){
                cout<<"Koniec gry dla: "<<g[i].nick;
            }
        }
        cout<<"Czy chcesz zagrac jeszcze raz?(tak lub nie)"<<endl;
        cin>>rozgrywka;
        if(rozgrywka=="nie"){
        cout<<"Czy chcesz zapisac gre?(tak lub nie)"<<endl;
        string mozliwosc;
        cin>>mozliwosc;
        if (mozliwosc=="tak"){
            fstream plik;
            plik.open("save.txt",ios::out);
            plik<<liczba_graczy<<endl;
            for(int i=0;i<liczba_graczy;i++){
                plik<<g[i].nick<<endl;
                plik<<g[i].monety<<endl;
            }}}
        system("cls");
        }
}

int wybor(){
    cout<<"Iloma koscmi chcesz rzucic?(1,2 lub 3)";
    int x;
    cin>>x;
    return x;
}

