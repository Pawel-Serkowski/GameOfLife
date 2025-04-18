#pragma once
#include <iostream>
#include "Swiat.hpp"

#include <typeinfo>
#include <cstdlib>

using namespace std;

struct Polozenie_t{
    int x;
    int y;
};

class Swiat;

class Organizm{
private:
    string ikona;
    int sila;
    int inicjatywa;//w turach
    
    
protected:
    Swiat *swiatRef;
    int dlugoscZycia;
    bool czyZyje;

    Polozenie_t polozenie;
    Polozenie_t poprzedniePolozenie;
    const int mozliweRuchy[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};//lewo, gora,prawo, dol    
public:
    Organizm(int x, int y, string icon, int sila, int inicjatywa);
    Organizm(const Organizm& copy);
    virtual ~Organizm(){};

    virtual void akcja() = 0;
    virtual void kolizja(Organizm *inny) = 0;
    virtual Organizm* dziecko() = 0;
    virtual bool czyUcieczka();

    int getX() const;
    int getY() const;
    int getSila() const;
    int getInicjatywa() const;
    int getDlugoscZycia() const;
    bool getCzyZyje();
    Polozenie_t getPoprzedniePolozenie();
    
    bool setPolozenie(Polozenie_t nowePolozenie, bool czyPuste=false);

    void zabij();
    void addDlugoscZycia();
    void rysowanie() const;
    void setSila(int sila);
    
    
    string toString();
};
