#include "Guarana.hpp"

Guarana::Guarana(int x, int y):Roslina("🌺",0,x,y){
    prawdopodobienstwo = 20;
}

void Guarana::kolizja(Organizm* atakujacyOrganizm){
    atakujacyOrganizm->setSila(atakujacyOrganizm->getSila()+3);
    swiatRef->dodajLog(this, "wzmocnila "+atakujacyOrganizm->toString());
    zabij();
}

Organizm* Guarana::dziecko()
{
	return new Guarana(*this);
}