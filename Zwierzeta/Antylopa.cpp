#include "Antylopa.hpp"

Antylopa::Antylopa(int x, int y, int sila, int wiek) : Zwierze("🦌",4,4,x,y,"Antylopa",wiek){};

void Antylopa::akcja(){
    int ruch = rand()%8;
    while(!setPolozenie({polozenie.x + ruchy[ruch][0],polozenie.y + ruchy[ruch][1]})){
        ruch++;
        ruch %= 8;
    }
}

bool Antylopa::czyUcieczka(){
    bool ucieczka = rand()%2;

    if(ucieczka){
        int ruch = 0;
        while(ruch < 8){
            if(!setPolozenie({polozenie.x + ruchy[ruch][0],polozenie.y + ruchy[ruch][1]},true)){
                swiatRef->dodajLog(this, "udalo sie uciec od walki");
                return true;
            }
            ruch++;
        }
        swiatRef->dodajLog(this,"nie udalo sie uciec");
    }
    return false;
}

Organizm* Antylopa::dziecko(){
    return new Antylopa(*this);
}