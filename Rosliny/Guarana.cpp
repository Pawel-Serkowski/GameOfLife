#include "Guarana.hpp"

Guarana::Guarana(int x, int y, int wiek):Roslina("🌺",0,x,y,"Guarana",wiek){
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