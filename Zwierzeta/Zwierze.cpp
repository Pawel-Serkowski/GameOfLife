#include "Zwierze.hpp"



Zwierze::Zwierze(string ikona, int sila, int inicjatywa, int x, int y) : Organizm(x,y,ikona, sila, inicjatywa){}

Zwierze::~Zwierze(){}


void Zwierze::akcja(){
    int ruch = rand()%4;
    while(!setPolozenie({mozliweRuchy[ruch][0]+polozenie.x,mozliweRuchy[ruch][1]+polozenie.y})){
        ruch++;
        ruch %= 4;
    }
}

void Zwierze::kolizja(Organizm *atakujacyOrganizm){
    if(this == atakujacyOrganizm){
        swiatRef->dodajLog(this, "spotkal siebie");
        return;
    }    
    if(typeid(*this) == typeid(*atakujacyOrganizm)){
        if(getDlugoscZycia()<2 || atakujacyOrganizm->getDlugoscZycia()<2)return;
        atakujacyOrganizm->setPolozenie(atakujacyOrganizm->getPoprzedniePolozenie());
        rozmnazanie();
        return;
    }

    if(czyUcieczka() || atakujacyOrganizm->czyUcieczka()){
        return;
    }

    if(atakujacyOrganizm->getSila() >= this->getSila()){
        swiatRef->dodajLog(atakujacyOrganizm, "wygrywa walke z "+toString());
        this->zabij();
    }else{
        swiatRef->dodajLog(this, "wygrywa walke z "+atakujacyOrganizm->toString());
        atakujacyOrganizm->zabij();
        return;
    }
}


void Zwierze::rozmnazanie(){
    auto dziecko = dynamic_cast<Zwierze*>(this->dziecko());
    int ruch = rand()%4;
    int i = 0;
    if(dziecko == nullptr){
        cout << "dupa" << "\n";
        return;
    }

    while(!dziecko->setPolozenie({polozenie.x+mozliweRuchy[ruch][0],polozenie.y+mozliweRuchy[ruch][1]},true)){
        if(i >= 4){
            swiatRef->dodajLog(this, "nie udalo sie rozmnozyc");
            dziecko->zabij();
            return;
        }
        i++;      
        ruch = (++ruch)%4;
    }
    swiatRef->dodajLog(this, "udalo sie rozmnozyc");
}


