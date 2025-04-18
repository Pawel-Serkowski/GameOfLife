#include "WilczeJagody.hpp"

WilczeJagody::WilczeJagody(int x, int y) : Roslina("🫐",99,x,y){
    this->prawdopodobienstwo = 20;
}

void WilczeJagody::kolizja(Organizm* atakujacyOrganizm){
    atakujacyOrganizm->zabij();
    swiatRef->dodajLog(atakujacyOrganizm,"zginął przez zjedzenie " + this->toString());
}

Organizm* WilczeJagody::dziecko(){
    return new WilczeJagody(*this);
}