#include "Roslina.hpp"

Roslina::Roslina(string ikona, int sila, int x, int y,string nazwa, int wiek):Organizm(x,y,ikona,sila,0,nazwa, wiek){};

void Roslina::akcja(){
    if(rand()%100+1 > prawdopodobienstwo)return;

    
    auto dziecko = dynamic_cast<Roslina*>(this->dziecko());
    int ruch = rand()%8;
    int i = 0;
    while(!dziecko->setPolozenie({polozenie.x+mozliweRuchy[ruch][0],polozenie.y+mozliweRuchy[ruch][1]},true)){
        if(i > 7){
            // swiatRef->dodajLog(this, "nie udalo sie zasiac nowej roslinki");
            dziecko->zabij();
            return;
        }
        i++;      
        ruch = (++ruch)%8;
    }
    swiatRef->dodajLog(this, "udalo sie zasiac nowa roslinke");
}

void Roslina::kolizja(Organizm* atakujacyOrganizm){
    if(this == atakujacyOrganizm)return;
    if(getSila() > atakujacyOrganizm->getSila()){
        swiatRef->dodajLog(this, "zatrul/a napastnika");
        atakujacyOrganizm->zabij();
        return;
    }
    swiatRef->dodajLog(this, "zostal/a zdeptana");
    this->zabij();
}
