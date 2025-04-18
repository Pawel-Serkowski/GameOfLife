#pragma once

#include <list>
#include <iostream>

#include "Organizm.hpp"

using namespace std;

class Organizm;
class Swiat{
private:
    list<unique_ptr<Organizm>> organizmy;
    int wysokosc;
    int szerokosc;
    int rozmiarRamki;
    int tura;
    int iloscZwierzat;
    string logiSymulacji;
    int nrLog;
    
    
    Swiat(int szerokosc, int wysokosc);
    void rysujRamke();
    void rysujLogi();
    void rysujSwiat();

    void wykonajTure();
    
    void posortujKolejnosc();
    
    void usunNiezyjaceOrganizmy();

    static Swiat* stanSwiata;
    
public:


    static Swiat* getStanSwiata();
    static Swiat* getStanSwiata(int szerokosc, int wysokosc);

    Organizm* getOrganizm(int x, int y);

    int getSzerokosc();
    int getWysokosc();
    
    void stworzPopulacje();
    void symulacja();
    
    void odejmijOrganizm();
    void dodajOrganizm(Organizm* organizm); 
    void dodajLog(Organizm* org,string log);

    ~Swiat();
};
