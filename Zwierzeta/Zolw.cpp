#include "Zolw.hpp"

Zolw::Zolw(int x, int y, int sila, int wiek) : Zwierze("🐢",2,1,x,y,"Zolw",wiek){};

void Zolw::akcja(){
    bool czyZmianaRuchu = rand()%4 == 3 ? true : false;
    if(czyZmianaRuchu){
        Zwierze::akcja();
        return;
    }
}

void Zolw::kolizja(Organizm* atakujacyOrganizm){
    if(atakujacyOrganizm->getSila() < 5){
        atakujacyOrganizm->setPolozenie(atakujacyOrganizm->getPoprzedniePolozenie());
        return;
    }
    Zwierze::kolizja(atakujacyOrganizm);
}

Organizm* Zolw::dziecko(){
    return new Zolw(*this);
}